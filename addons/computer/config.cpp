#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "krzycac_main",
            "cba_main",
            "ace_common"
        };
        authors[] = {"Krzyciu"};
        author = "Krzyciu";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgEventHandlers.hpp"
#include "dialog.hpp"