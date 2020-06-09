#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager *pApp): Action(pApp) {}

void AddLineAction::ReadActionParameters(){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at start point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(start.x, start.y);

	pOut->PrintMessage("New Line: Click at end point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(end.x, end.y);

	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddLineAction::Execute()
{
	ReadActionParameters();

	CLine *L = new CLine(start, end, LineGfxInfo);

	pManager->AddFigure(L);
}