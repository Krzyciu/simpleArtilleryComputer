#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"

if !(hasInterface) exitWith {};

[LLSTRING(computer), QGVAR(openComputer), LLSTRING(Action_OpenComputer), {
  if !(0 call FUNC(canUseComputer)) exitWith {};
  0 call FUNC(createDialog)
}, {}, [DIK_P, [false, false, false]]] call CBA_fnc_addKeybind;