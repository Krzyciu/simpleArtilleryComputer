class CfgWeapons {
	class CBA_MiscItem;
    class CBA_MiscItem_ItemInfo;

    class GVAR(artilleryComputer): CBA_MiscItem {
		scope = 2;
		author = "Krzyciu";
		displayName = CSTRING(artilleryComputer_mainName);
		descriptionShort = CSTRING(artilleryComputer_descriptionShort);
		model = "\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d";
		picture= QPATHTOF(data\tablet.paa);

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
	};
};
