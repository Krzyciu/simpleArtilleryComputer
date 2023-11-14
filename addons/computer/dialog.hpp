class RscButton;
class RscEdit;
class RscListBox;
class RscText;
class RscTitle;
class RscPicture;

class GVAR(artilleryComputer) {
	idd = IDC_ARTILLERYCOMPUTER;
	name= QGVAR(artilleryComputer);

	enableSimulation = 1;
	movingEnable = 0;

	onLoad = QUOTE(_this call FUNC(onDialogLoad));
	onUnload = QUOTE(_this call FUNC(onDialogUnload));

	class Objects {
	    class GVAR(backgroundTablet) {
			idc = -1;
			type = 82;
			model = QUOTE(\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d);

			direction[] = {0,-1,0};
			up[] = {0,1,-1};
			
			x = 0.5;
			y = 0.5;
			z = 0.2;

			xBack = 0.5;
			yBack = 0.5;
			zBack = 0.2;

			inBack = 0;

			scale = 1;
			enableZoom = 0;
			zoomDuration = 0.001;
			onLoad = QUOTE((_this select 0) ctrlEnable false);
		};
	};
	
	class controls {
		class Background: RscText {
			x = 0;
			y = 0;
			w = 1;
			h = 1;
			
			colorBackground[] = {0.15, 0.15, 0.15, 1};
		};
		
		class GVAR(ownGrid): RscText {
			x = QUOTE(23 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(2 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(5 * GUI_GRID_W);
			h = QUOTE(2 * GUI_GRID_H);
			
			text = CSTRING(artilleryComputer_ownGrid);
			tooltip = CSTRING(artilleryComputer_ownGrid_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};
		
		class GVAR(ownGridX): RscText {
			x = QUOTE(23 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(4 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(X);
			tooltip = CSTRING(artilleryComputer_ownGridX_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};
		
		class GVAR(ownGridY): RscText {
			x = QUOTE(23 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(6 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(Y);
			tooltip = CSTRING(artilleryComputer_ownGridY_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(editOwnGridX): RscEdit {
			idc = IDC_OWNGRID_X;

			maxChars = 5;
			x = QUOTE(24 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(4 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};
		
		class GVAR(editOwnGridY): RscEdit {
			idc = IDC_OWNGRID_Y;

			maxChars = 5;
			x = QUOTE(24 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(6 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};

		class GVAR(targetGrid): RscText {
			x = QUOTE(29 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(2 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(5 * GUI_GRID_W);
			h = QUOTE(2 * GUI_GRID_H);

			text = CSTRING(artilleryComputer_targetGrid);
			tooltip = CSTRING(artilleryComputer_targetGrid_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(targetGridX): RscText {
			x = QUOTE(29 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(4 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(X);
			tooltip = CSTRING(artilleryComputer_targetGridX_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(targetGridY): RscText {
			x = QUOTE(29 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(6 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(Y);
			tooltip = CSTRING(artilleryComputer_targetGridY_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(editTargetGridX): RscEdit {
			idc = IDC_TARGETGRID_X;

			maxChars = 5;
			x = QUOTE(30 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(4 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};
		
		class GVAR(editTargetGridY): RscEdit {
			idc = IDC_TARGETGRID_Y;

			maxChars = 5;
			x = QUOTE(30 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(6 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};

		class GVAR(targetDir): RscText {
			x = QUOTE(22 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(10 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(DIR);
			tooltip = CSTRING(artilleryComputer_targetDir_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(targetElev): RscText {
			x = QUOTE(22 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(12 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(ELEV);
			tooltip = CSTRING(artilleryComputer_targetElev_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(targetDist): RscText {
			x = QUOTE(22 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(14 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(DIS);
			tooltip = CSTRING(artilleryComputer_targetDist_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(editTargetDir): RscEdit {
			idc = IDC_TARGETDIR;
			maxChars = 4;

			x = QUOTE(24 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(10 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};

		class GVAR(editTargetElev): RscEdit {
			idc = IDC_TARGETELEV;

			x = QUOTE(24 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(12 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};

		class GVAR(editTargetDist): RscEdit {
			idc = IDC_TARGETDIST;

			x = QUOTE(24 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(14 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
		};

		class GVAR(chargeText): RscText {
			x = QUOTE(4 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(2 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(Charge);
		};

		class GVAR(charge): RscListBox {
			idc = IDC_CHARGE_LIST;

			x = QUOTE(4 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(3 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(14 * GUI_GRID_W);
			h = QUOTE(12 * GUI_GRID_H);
		
			onLBSelChanged = QUOTE(playSound 'click');
		};
		
		class GVAR(buttonApply): RscButton {
			idc = IDC_BUTTON_APPLY;
			x = QUOTE(18 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(19 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3.2 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);

			text = CSTRING(artilleryComputer_buttonApply);
			tooltip = CSTRING(artilleryComputer_buttonApply_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
			
			onButtonClick = QUOTE(playSound 'click'; 0 call FUNC(calculate));
		};
		
		class GVAR(buttonClose): RscButton {
			x = QUOTE(19.5 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(27.7 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(1 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);

			tooltip = CSTRING(artilleryComputer_closeButtonTooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
			colorBackground[] = {0,0,0,0};
			
			onButtonClick = QUOTE((findDisplay IDC_ARTILLERYCOMPUTER) closeDisplay 0);
		};

		class GVAR(connectToDagr): RscButton {
			idc = IDC_BUTTON_CONNECT;
			x = QUOTE(10 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(19 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			access = 0;
			type = 1;
			text = "";
			colorText[] = {0, 0, 0, 0 };
			colorDisabled[] = {0, 0, 0, 0  };
			colorBackground[] = {0, 0, 0, 0 };
			colorBackgroundDisabled[] = {0, 0, 0, 0 };
			colorBackgroundActive[] = {0, 0, 0, 0 };
			colorFocused[] = {0, 0, 0, 0 };
			colorShadow[] = {0, 0, 0, 0 };
			colorBorder[] = {0, 0, 0, 0 };
			
			onButtonClick = QUOTE(playSound 'click'; 0 call FUNC(gpsPosition));
		};

		class GVAR(connectText): RscText {
			x = QUOTE(8 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(19 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(3 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			
			text = QUOTE(GPS);
			tooltip = CSTRING(artilleryComputer_buttonConnect_tooltip);
			tooltipColorText[] = {0.543, 0.5742, 0.4102, 1.0};
			tooltipColorBox[] = {1,1,1,0};
			tooltipColorShade[] = {0,0,0,0};
		};

		class GVAR(connectPicture): RscPicture {
			x = QUOTE(10 * GUI_GRID_W + GUI_GRID_CENTER_X);
			y = QUOTE(19 * GUI_GRID_H + GUI_GRID_CENTER_Y);
			w = QUOTE(1 * GUI_GRID_W);
			h = QUOTE(1 * GUI_GRID_H);
			text = QUOTE(\a3\ui_f\data\igui\cfg\simpletasks\types\move_ca.paa);
		};
	};
};