#include "script_component.hpp"
/*
 * Author: Krzyciu
 * Gets own position if GPS/MicroDagr present in equipment.
*/

if (
  ("ItemGPS" in (assigneditems ace_player) ) || 
  ([ace_player, "ItemGPS"] call ace_common_fnc_hasItem) || 
  {[ace_player, "ACE_microDAGR"] call ace_common_fnc_hasItem}
) then {
  private _pos = [getPos player] call ace_common_fnc_getMapGridFromPos;
  private _easting = _pos #0;
  private _northing = _pos #1;
  private _display = findDisplay IDC_ARTILLERYCOMPUTER;
  private _xOwn = _display displayCtrl IDC_OWNGRID_X; 
  private _yOwn = _display displayCtrl IDC_OWNGRID_Y;
  _xOwn ctrlSetText _easting;
  _yOwn ctrlSetText _northing;
} else {
  systemChat LLSTRING(noGPS);
};
