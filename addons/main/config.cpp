#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
          "cba_common",
          "cba_main",
          "ace_main"
        };
        authors[] = {"Krzyciu"};
        author = "Krzyciu";
        VERSION_CONFIG;
    };
};
