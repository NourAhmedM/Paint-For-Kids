#include "DelAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DelAction::DelAction(ApplicationManager *pApp):Action(pApp){}

void DelAction::ReadActionParameters()
{}

void DelAction::Execute()
{
	Output * pOut = pManager->GetOutput();

	if(pManager->getSelectedFig())
	{
		pOut->PrintMessage("The figure is deleted");
		pManager->DeleteSelectedFigure();
	}
	else
		pOut->PrintMessage("Please select a figure first");
}
