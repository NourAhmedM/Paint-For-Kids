#include "Output.h"
#include <cmath>


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;		//The startup window

	UI.width = 1400;		//The width of the window
	UI.height = 650;		//The height of the window
	UI.wx = 5;
	UI.wy =5;


	UI.StatusBarHeight = 50;		//The height of the status bar
	UI.ToolBarHeight = 50;			//The height of the toolbar
	UI.MenuItemWidth = 60;			//The width of the icon
	UI.ToolBarColor = WHITE;		//Defualt color of the toolbar

	UI.Filled = false;		//Default figures are non-filled
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = BLUE;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTPINK;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;	//Color of the status bar
	UI.PenWidth = 3;	//default width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();	//Draws the drawing mode toolbar
	CreateStatusBar();		//Creates the status bar
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);

	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
////////////////////////////////////////////////////////////////////////////////

//A function to clear the ToolBar to be used when changing between Draw and Play mode
void  Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0,0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	//Adding icons of each item in the toolbar
	MenuItemImages[ITM_RECT] = "images\\ADDED IMAGES\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\ADDED IMAGES\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRN] = "images\\ADDED IMAGES\\Menu_Trian.jpg";
	MenuItemImages[ITM_LINE] = "images\\ADDED IMAGES\\Menu_Line.jpg";	
	MenuItemImages[ITM_FRM] = "images\\ADDED IMAGES\\Frame.jpg";
	MenuItemImages[ITM_Fill] = "images\\ADDED IMAGES\\Fill.jpg";
	MenuItemImages[ITM_RED] = "images\\ADDED IMAGES\\Red.jpg";
	MenuItemImages[ITM_BLUE] = "images\\ADDED IMAGES\\Blue.jpg";
	MenuItemImages[ITM_WHT] = "images\\ADDED IMAGES\\White.jpg";
	MenuItemImages[ITM_GRN] = "images\\ADDED IMAGES\\Green.jpg";
	MenuItemImages[ITM_BLCK] = "images\\ADDED IMAGES\\Black.jpg";
	MenuItemImages[ITM_SLKT] = "images\\ADDED IMAGES\\Select.jpg";
	MenuItemImages[ITM_DLT] = "images\\ADDED IMAGES\\Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\ADDED IMAGES\\Save.jpg";
	MenuItemImages[ITM_CUT] = "images\\ADDED IMAGES\\Cut.jpg";
	MenuItemImages[ITM_CPY] = "images\\ADDED IMAGES\\Copy.jpg";
	MenuItemImages[ITM_PST] = "images\\ADDED IMAGES\\Paste.jpg";
	MenuItemImages[ITM_PLYMODE] = "images\\ADDED IMAGES\\PlayMode.jpg";
	MenuItemImages[ITM_LOAD] = "images\\ADDED IMAGES\\Load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\ADDED IMAGES\\Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	//Adding icons of each icon in the toolbar

	string PlayItems [PLAY_ITM_COUNT];
	PlayItems[Itm_Type] =		"images\\ADDED IMAGES\\type.jpg";
	PlayItems[Itm_Type_Color] =	"images\\ADDED IMAGES\\TypeAndColor.jpg";
	PlayItems[Itm_Color] =		"images\\ADDED IMAGES\\color.jpg";
	PlayItems[Itm_To_Draw] =	"images\\ADDED IMAGES\\DrawMode.jpg";
	PlayItems[Itm_Exit] =		"images\\ADDED IMAGES\\Exit.jpg";

	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItems[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,3);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawCirc(Point P1,Point P2,GfxInfo CircGfxInfo,bool selected) const
{
	double radius = sqrt(pow((P1.y-P2.y),2) + pow((P1.x-P2.x),2)); //calculating the radius
	color DrawingClr;

	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,3);
	drawstyle style;

	if (CircGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	pWind->DrawCircle(P1.x,P1.y,radius,style);


}

void Output::DrawTri(Point P1,Point P2,Point P3,GfxInfo TriGfxInfo,bool selected)const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr =TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,3);
	drawstyle style;
	if (TriGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	pWind->DrawTriangle(P1.x,P1.y,P2.x,P2.y,P3.x,P3.y,style);
}

void Output::DrawLine(Point p1,Point p2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,3);

	pWind->DrawLine(p1.x, p1.y, p2.x, p2.y);

}



//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}