#include "CutAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"


CutAction::CutAction(ApplicationManager* pMan):Action(pMan)
{}

void CutAction::ReadActionParameters()
{}

void CutAction::Execute()
{

	Output* pOut = pManager->GetOutput();

	CFigure *ptr;    CFigure *ptro;

	ptr=pManager->getSelectedFig();

	if(ptr==NULL)
		pOut->PrintMessage("please selsect a figure first");
	else
	{
		ptro=ptr->copy();
		pManager->SetClipboard(ptro);

		pManager->DeleteSelectedFigure();

	}
}