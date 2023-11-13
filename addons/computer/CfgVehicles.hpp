class CfgVehicles {
    class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Equipment {
                class GVAR(useArtilleryComputer) {
                    displayName = CSTRING(Action_OpenComputer);
                    condition = QUOTE(0 call FUNC(canUseComputer));
                    statement = QUOTE(createDialog 'krzycac_computer_artilleryComputer');
                    showDisabled = 0;
                    exceptions[] = {};
                    icon = "";
                };
			};
		};
	};
};