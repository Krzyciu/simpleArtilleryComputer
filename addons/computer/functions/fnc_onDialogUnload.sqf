#include "script_component.hpp"

params ["_display"];
private _xOwn = ctrlText (_display displayCtrl IDC_OWNGRID_X); 
private _yOwn = ctrlText (_display displayCtrl IDC_OWNGRID_Y);
private _xTarget = ctrlText (_display displayCtrl IDC_TARGETGRID_X); 
private _yTarget = ctrlText (_display displayCtrl IDC_TARGETGRID_Y);
private _dir = ctrlText (_display displayCtrl IDC_TARGETDIR);
private _dis = ctrlText (_display displayCtrl IDC_TARGETDIST);
private _elev = ctrlText (_display displayCtrl IDC_TARGETELEV);
private _charge = lbCurSel (_display displayCtrl IDC_CHARGE_LIST);

ace_player setVariable [QGVAR(computerData), [_xOwn, _yOwn, _xTarget, _yTarget, _dir, _dis, _elev, _charge]];