#include "script_component.hpp"

params ["_display"];
private _ctrlChargeList = _display displayCtrl IDC_CHARGE_LIST;
private _ctrlAngle = _display displayCtrl IDC_ANGLE;
private _ctrlGrid = _display displayCtrl IDC_GRID;

private _data = ace_player getVariable [QGVAR(computerData), ["000", "000", "000", "000", "", "", "", 0, "", 1, 4]];
_data params ["_xOwn", "_yOwn", "_xTarget", "_yTarget", "_dir", "_dis", "_elev", "_charge", "_tof", "_angle", "_grid"];

private _vehicles = nearestObjects [ace_player, ["LandVehicle"], 25];
{
  [_x, _ctrlChargeList] call FUNC(addNewWeapon);
} forEach _vehicles;

(_display displayCtrl IDC_OWNGRID_X) ctrlSetText _xOwn;
(_display displayCtrl IDC_OWNGRID_Y) ctrlSetText _yOwn;
(_display displayCtrl IDC_TARGETGRID_X) ctrlSetText _xTarget; 
(_display displayCtrl IDC_TARGETGRID_Y) ctrlSetText _yTarget;
(_display displayCtrl IDC_TARGETDIR) ctrlSetText _dir;
(_display displayCtrl IDC_TARGETDIST) ctrlSetText _dis;
(_display displayCtrl IDC_TARGETELEV) ctrlSetText _elev;
(_display displayCtrl IDC_TARGETTOF) ctrlSetText _tof;
_ctrlChargeList lbSetCurSel _charge;
_ctrlAngle lbSetCurSel _angle;
_ctrlGrid lbSetCurSel _grid;