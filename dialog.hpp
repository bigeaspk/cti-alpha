class RscText
{
	access = 0;			//0 - Read and Write, 1 - Read and create, 2 - Read, 3 - Read verified
	type = CT_STATIC;	//type of the control
	idc = -1;			//control ID number
	style = ST_LEFT;	//style of the control
	w = 0.5;			//width (0-1)
	h = 0.5;			//height (0-1)
	x = 0.5;			//position on X axis (0-1)
	y = 0.5;			//position on Y axis (0-1)
	font = GUI_FONT_NORMAL;		//font style
	sizeEx = 0.04;				//font size
	colorBackground[] = { 0,0,0,1 };		//background color, RGBA format (currently transparent)
	colorText[] = { 1,1,1,1 };			//background color, RGBA format (currently white)
	text = "TEXT EXAMPLE";				//text field
	fixedWidth = 0;				//0,1
	shadow = 0;				//0 - none, 1 - color affected by background, 2 - black
};	//end: RscText class

class MyFirstDialog			//Dialog class name, gets called by: handle = CreateDialog "name"
	{
	idd=6000;					//Display control number
	movingenable=false;			//True/False to enable moving the dialog with mouse
	enableSimulation = 1;		//True/False to enable world simulation in the background
	class controls {
		class RscButton
		{
    
  			access = 0;				//same as above
			idc = -1;				//ID number
			type = CT_BUTTON;		//type of the control
			text = "BUTTON";		//text field
			colorText[] = {1,1,1,1};		//color of the text (currently white)
			colorDisabled[] = {0.4,0.4,0.4,0};		//color when disabled (currently gray)
			colorBackground[] = {0,0,1,1};			//background color (currently blue)
			colorBackgroundDisabled[] = {0.9,0.9.0.9,0};		//background color when disabled (currently light gray)
			colorBackgroundActive[] = {1,0,0,1};		//background color when active (selected, or hovered over) (currently red)
			colorFocused[] = {0,1,0,1};			//bakcground color when focused (selected) (currently green)
			colorShadow[] = {0.023529,0,0.0313725,0};		//shadow color (currently dark gray)
			colorBorder[] = {0.023529,0,0.0313725,0};		//border color (currently dark gray)
  			soundEnter[] = {"",0.09,1};			//sound upon hovering over the control (sound, volume, pitch)
    		soundPush[] = {"",0,0};			//sound upon pushing the button (sound, volume, pitch)
    		soundClick[] = {"",0.07,1};			//sound upon clicking the button (sound, volume, pitch)
    		soundEscape[] = {"",0.09,1};		//sound upon releasing the pushed button (sound, volume, pitch)
			x = 0.5;			//position on X axis (0-1)
			y = 0.8;			//position on Y axis (0-1)
			w = 0.2;			//width (0-1)
			h = 0.1;			//height (0-1)
    		style = 2;		//style of the control
    		shadow = 2;			//above
    		font = GUI_FONT_BOLD;	//font type
    		sizeEx = 0.05;			//font size
    		offsetX = 0;		//offset when not pressed on X axis
    		offsetY = 0;		//offset when not pressed on Y axis
    		offsetPressedX = 0.003;			//offset when pressed on X axis
    		offsetPressedY = 0.003;			//offset when pressed on Y axis
    		borderSize = 0;			//border size (duh)
			action = "closedialog 0";	//action executed upon clicking the button (currently closes the dialog itself)
		};		//end: RscButton class
	};	//end: controls class
};	//end: MyFirstDialog class

class captureBar
{
	idd = 6001;
	duration = 1e+011;
	movingenable = false;
	enableSimulation = false;
	onLoad = uiNamespace setVariable ["captureBar", _this select 0];
	onUnLoad = uiNamespace setVariable ["captureBar", nil];
	class controls
	{
		class greyBar : RscText
		{
			idc = 1001;
			x = (safeZoneX + (safeZoneWAbs / 2) - 0.15);
			y = safeZoneY + 0.15;
			h = 0.3;
			w = 0.3;
			style = ST_PICTURE;
			colorText[] = { 1,1,1,0.6 };
			text = "images\zoneCapture\greyBar.paa";
		};
		class bluforBar : greyBar
		{
			idc = 1002;
			w = 0;
			text = "images\zoneCapture\bluforBar.paa";
		};
		class opforBar : greyBar
		{
			idc = 1003;
			w = 0;
			text = "images\zoneCapture\opforBar.paa";
		};
		class greyBarOutline : greyBar
		{
			idc = 1004;
			style = ST_WITH_RECT;
			h = 0.023469;
			text = "";
			colorText[] = { 0,0,0,1 };
		};
	};
};

class objectiveName
{
	idd = 6002;
	duration = 1e+011;
	movingEnable = false;
	enableSimulation = false;
	class controls
	{
		class objectiveText : RscText
		{
			idc = 1005;
			type = CT_STRUCTURED_TEXT;
			style = ST_CENTER;
			size = 0.06;
			x = safeZoneX;
			y = safeZoneY + 0.07;
			w = safeZoneWAbs;
			h = 1;
			text = <t shadow='1' shadowColor='#CC000000' align='center'>Camp Rogain</t>;
			colorText[] = { 1,1,1,1 };
			colorBackground[] = { 0,0,0,0 };
		};
	};
};