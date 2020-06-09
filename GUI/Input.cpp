#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int x,int y,bool check) const
{	
	if(check)
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRN: return DRAW_TRI;
			case ITM_LINE: return DRAW_LINE;
			case ITM_FRM: return CHNG_DRAW_CLR;
			case ITM_Fill: return CHNG_FILL_CLR;
			case ITM_DLT: return DEL;
			case ITM_LOAD: return LOAD;
			case ITM_SAVE: return SAVE;
			case ITM_PLYMODE: return TO_PLAY;
			case ITM_CPY: return COPY;

			case ITM_BLCK: return FBLACK;
			case ITM_BLUE: return FBLUE;
			case ITM_RED: return FRED;
			case ITM_GRN: return FGREEN;
			case ITM_WHT: return FWHITE;

			case ITM_SLKT: return SELECT;
			case ITM_PST: return PASTE;
			case ITM_CUT: return CUT;

			case ITM_EXIT: return EXIT;	

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder){
			case Itm_Color: return COLOR;
			case Itm_Type: return TYPE;
			case Itm_Type_Color: return TYPE_N_COLOR;
			case Itm_To_Draw: return TO_DRAW;
			case Itm_Exit: return EXIT;
			default: return EMPTY;
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}


		return STATUS;
	}	

}
/////////////////////////////////

Input::~Input()
{
}
