#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


addTriAction::addTriAction(ApplicationManager *pApp):Action(pApp){}
	
	
void addTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first vertex");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second vertex");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third vertex");

	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = UI.Filled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

//Execute the action
void addTriAction::Execute() 
{
	ReadActionParameters();
	
	
	CTriangle *T=new CTriangle(P1, P2,P3, TriGfxInfo);
	pManager->AddFigure(T);
}

