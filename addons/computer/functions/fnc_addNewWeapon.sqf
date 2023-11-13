#include "script_component.hpp"
/*
 * Author: PabstMirror, Krzyciu
 * Find charges of nearby artillery vehicles.
 */
params ["_vehicle", "_ctrlChargeList"];
private _vehicleCfg = configOf _vehicle;
private _turret = [];
private _turretCfg = configNull;
{
	private _xTurretCfg = [_vehicleCfg, _x] call CBA_fnc_getTurret;
	if ((getNumber (_xTurretCfg >> "primaryGunner")) == 1) exitWith {
		_turret = _x;
		_turretCfg = _xTurretCfg;
	};
} forEach allTurrets _vehicle;


private _weaponsTurret = _vehicle weaponsTurret _turret;

if ((count _weaponsTurret) != 1) exitWith {
  WARNING_1("multiple weapons - %1",configName _vehicleCfg); 
};

private _weapon = _weaponsTurret #0;

private _turretAnimBody = getText (_turretCfg >> "animationSourceBody");
private _turretAnimGun = getText (_turretCfg >> "animationSourceGun");

// For artillery with detached camera (I_Truck_02_MRL_F) need to use animationSourcePhase
// But that command won't always work, so fallback to animationPhase
private _currentElevRad = _vehicle animationSourcePhase _turretAnimGun;
if (isNil "_currentElevRad") then { _currentElevRad = _vehicle animationPhase _turretAnimGun; };
private _currentTraverseRad = _vehicle animationSourcePhase _turretAnimBody;
if (isNil "_currentTraverseRad") then { _currentTraverseRad = _vehicle animationPhase _turretAnimBody; };

// Some turrets (MK6) have a neutralX rotation that we need to add to min/max config elevation to get actual limits
private _weaponDir = _vehicle weaponDirection _weapon;
private _turretRot = [vectorDir _vehicle, vectorUp _vehicle, deg _currentTraverseRad] call CBA_fnc_vectRotate3D;
private _neutralX = (acos ((_turretRot vectorCos _weaponDir) min 1)) - (deg _currentElevRad); // vectorCos can return values outside of -1..1
_neutralX = (round (_neutralX * 10)) / 10; // minimize floating point errors
private _minElev = _neutralX + getNumber (_turretCfg >> "minElev");
private _maxElev = _neutralX + getNumber (_turretCfg >> "maxElev");


private _mags = [_weapon] call CBA_fnc_compatibleMagazines;

if (_mags isEqualTo []) exitWith {
  WARNING_1("No Mags",_weapon);
};

private _magCfg = configFile >> "CfgMagazines";
private _magParamsArray = [];
_mags = _mags apply {
    private _initSpeed = getNumber (_magCfg >> _x >> "initSpeed");
    _magParamsArray pushBackUnique _initSpeed;
    private _airFriction = 0;
    if (_advCorrection) then {
        _airFriction = if (isNumber (_magCfg >> _x >> QGVAR(airFriction))) then { getNumber (_magCfg >> _x >> QGVAR(airFriction)) } else { DEFAULT_AIR_FRICTION };
    };
    _magParamsArray pushBackUnique _airFriction;
    [getText (_magCfg >> _x >> "displayNameShort"), getText (_magCfg >> _x >> "displayName"), _initSpeed, _airFriction]
};
_mags = _mags arrayIntersect _mags;
TRACE_2("",_magParamsArray,_mags);
if ((count _magParamsArray) == 2) then { // test if all magazines share the parameters
    _mags = [["", "All Magazines", (_mags select 0) select 2, (_mags select 0) select 3]]; // simplify
};

// Get Firemodes:
private _fireModes = getArray (configFile >> "CfgWeapons" >> _weapon >> "modes");
_fireModes = (_fireModes apply {configFile >> "CfgWeapons" >> _weapon >> _x}) select {1 == getNumber (_x >> "showToPlayer")};
_fireModes = _fireModes apply {[getNumber (_x >> "artilleryCharge"), configName _x]};
_fireModes sort true;
private _allSameCharge = ((count _fireModes) == 1) && {((_fireModes select 0) select 0) == 1};
TRACE_2("",_allSameCharge,_fireModes);
GVAR(magModeData) = [];
private _minRange = 0;
private _maxRange = 0;
private _finalVel = 0;
private _index = 0;

{
  _x params ["_xDisplayNameShort", "_xDisplayName", "_xInitSpeed"];
  if (_allSameCharge) then {
    _minRange = floor (_xInitSpeed^2*SINALPHAMIN/100)*100;
    _maxRange = floor (_xInitSpeed^2/GRAVITY/100)*100;
    _index = _ctrlChargeList lbAdd format ["%1 Range %2-%3m", _xDisplayNameShort, _minRange, _maxRange];
    _ctrlChargeList lbSetTooltip [count GVAR(magModeData), format ["%1\n%2 m/s", _xDisplayName, _xInitSpeed toFixed 1]];
    GVAR(magModeData) pushBack [_xInitSpeed, _minElev, _maxElev, _minRange, _maxRange];
  } else {
    {
      _x params ["_xModeCharge"];
      _finalVel = _xInitSpeed * _xModeCharge;
      _minRange = floor (_finalVel^2*SINALPHAMIN/GRAVITY/100)*100;
      _maxRange = floor (_finalVel^2/GRAVITY/100)*100;
      _index = _ctrlChargeList lbAdd format ["[Charge %1] %2 Range %3-%4m", _forEachIndex, _xDisplayNameShort, _minRange, _maxRange]; // forEachIndex is from firemodes
      _ctrlChargeList lbSetTooltip [count GVAR(magModeData), format ["%1\n%2 m/s", _xDisplayName, (_finalVel) toFixed 1]];
      GVAR(magModeData) pushBack [_finalVel, _minElev, _maxElev, _minRange, _maxRange];
    } forEach _fireModes;
  };
} forEach _mags;
