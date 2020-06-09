#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_TRN,		//Triangle item in menu
	ITM_LINE,		//Line item in menu
	
	ITM_FRM,		//Frame item in menu
	ITM_Fill,		//Filling item in menu

	ITM_RED,		// Frame color(red)
	ITM_BLUE,		//Frame color(Blue)
	ITM_GRN,		//Frame color(Green)
	ITM_WHT,		//Frame color(white)
	ITM_BLCK,		//Frame color(Black)
	ITM_SLKT,		//Selecting item in menu
	
	ITM_CPY,		//copy figure item in menu
	ITM_CUT,		//cut figure item in menu
	ITM_PST,		//Paste figure item in menu
	
	ITM_SAVE,		//save figure item in menu
	ITM_LOAD,		//load figure item in menu
	
	ITM_DLT,		//Deleting item in menu
	ITM_PLYMODE,	//switch to play mode item in menu

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	Itm_Type,
	Itm_Color,
	Itm_Type_Color,
	Itm_To_Draw,
	Itm_Exit,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	
	bool Filled;			//Determines if the default figure is filled or not
	color ToolBarColor;		//ToolBarColor
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif