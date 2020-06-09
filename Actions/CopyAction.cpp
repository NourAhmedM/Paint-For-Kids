#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CFigure.h"

CopyAction:: CopyAction(ApplicationManager* pMan):Action(pMan)
{}

void CopyAction:: ReadActionParameters()
{}

void CopyAction:: Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure *ptr;    CFigure *ptro;

	ptr=pManager->getSelectedFig();

	if(ptr==NULL)
		pOut->PrintMessage("please selsect a figure first!");
	else
	{
		ptro=ptr->copy();
		pManager->SetClipboard(ptro);
		pOut->PrintMessage("Figure is copied");
	}
}
