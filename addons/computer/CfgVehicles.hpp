class CfgVehicles {
    class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Equipment {
                class GVAR(useArtilleryComputer) {
                    displayName = CSTRING(Action_OpenComputer);
                    condition = QUOTE(0 call FUNC(canUseComputer));
                    statement = QUOTE(_this call FUNC(createDialog));
                    showDisabled = 0;
                    exceptions[] = {"isNotInside"};
                    icon = "";
                };
			};
		};
	};
};