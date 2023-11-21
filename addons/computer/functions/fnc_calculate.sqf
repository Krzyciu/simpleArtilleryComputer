#include "script_component.hpp"

private _display = findDisplay IDC_ARTILLERYCOMPUTER;
private _xOwn = ctrlText (_display displayCtrl IDC_OWNGRID_X); 
private _yOwn = ctrlText (_display displayCtrl IDC_OWNGRID_Y);
private _xTarget = ctrlText (_display displayCtrl IDC_TARGETGRID_X); 
private _yTarget = ctrlText (_display displayCtrl IDC_TARGETGRID_Y);
private _dir = ctrlText (_display displayCtrl IDC_TARGETDIR);
private _dis = ctrlText (_display displayCtrl IDC_TARGETDIST);
private _elev = ctrlText (_display displayCtrl IDC_TARGETELEV);
private _ctrlChargeList = _display displayCtrl IDC_CHARGE_LIST;
GVAR(lastCharge) = lbCurSel _ctrlChargeList;
(GVAR(magModeData) select GVAR(lastCharge)) params [["_finalVel", 0], ["_minElev", 10], ["_maxElev", 90], ["_minRange", 10], ["_maxRange", 10000]];
private _gridPosOwn = _xOwn + _yOwn;
private _realPosOwn = [_gridPosOwn] call ace_common_fnc_getMapPosFromGrid;

if (typeName _realPosOwn isNotEqualTo "ARRAY") exitWith {
  systemChat LLSTRING(wrongOwnGrid);
};
private _zOwn = getTerrainHeightASL _realPosOwn;

private _gridPosTarget = _xTarget + _yTarget;
private _realPosTarget = [_gridPosTarget] call ace_common_fnc_getMapPosFromGrid;

if (typeName _realPosTarget isNotEqualTo "ARRAY") exitWith {
  systemChat LLSTRING(wrongTargetGrid);
};

private _azimuth = round ((_realPosOwn getDir _realPosTarget)*17.777778);
private _distance = round (_realPosOwn distance2d _realPosTarget);

if (_distance > _maxRange || _distance < _minRange) exitWith {
  systemChat LLSTRING(wrongDistance);
  (_display displayCtrl IDC_TARGETDIR) ctrlSetText "0";
  (_display displayCtrl IDC_TARGETDIST) ctrlSetText "0";
  (_display displayCtrl IDC_TARGETELEV) ctrlSetText "0";
  (_display displayCtrl IDC_TARGETTOF) ctrlSetText "0";
};

private _zOwn = getTerrainHeightASL _realPosOwn;
private _zTarget = getTerrainHeightASL _realPosTarget;
private _zdiff = _zTarget - _zOwn;

(_display displayCtrl IDC_TARGETDIR) ctrlSetText str _azimuth;
(_display displayCtrl IDC_TARGETDIST) ctrlSetText str _distance;

private _elev = (atan((_finalVel^2+sqrt(_finalVel^4-GRAVITY*(GRAVITY*(_distance^2)+2*_zDiff*_finalVel^2)))/(GRAVITY*_distance)));

if (_elev > _maxElev || _elev < _minElev) exitWith {
  systemChat LLSTRING(wrongElevation);
  (_display displayCtrl IDC_TARGETDIR) ctrlSetText "0";
  (_display displayCtrl IDC_TARGETDIST) ctrlSetText "0";
  (_display displayCtrl IDC_TARGETELEV) ctrlSetText "0";
  (_display displayCtrl IDC_TARGETTOF) ctrlSetText "0";
};
private _tof = round ((2*_finalVel*sin(_elev))/GRAVITY);

_elev = _elev * DEGTOMILS;
_elev = round _elev;

(_display displayCtrl IDC_TARGETELEV) ctrlSetText str _elev;
(_display displayCtrl IDC_TARGETTOF) ctrlSetText str _tof;