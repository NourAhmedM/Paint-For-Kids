#include "PasteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PasteAction:: PasteAction(ApplicationManager* pMan):Action(pMan)
{}


void PasteAction:: ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on the Drawing Area to paste");

	pIn->GetPointClicked(p1.x,p1.y);

	pOut->ClearStatusBar();

}


void PasteAction:: Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* ptr,*ptro;

	if(pManager->GetClipboard())
	{
		ReadActionParameters();

		ptr=pManager->GetClipboard();

		ptro=ptr->paste(p1);

		pManager->AddFigure(ptro);
	}

	else
	{
		pOut->PrintMessage("please copy or cut a figure first");
	}
}