#include "ChngFillColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngFillColor::ChngFillColor(ApplicationManager *pApp): Action(pApp){ c = pApp->GetOutput()->getCrntDrawColor(); changed = false; }

void ChngFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType Act;

	pOut->PrintMessage("Please choose a color");

	Act = pIn->GetUserAction();
	switch (Act){
	case FRED: c = RED; changed = true; break;
	case FBLUE: c = BLUE; changed = true; break;
	case FBLACK: c = BLACK; changed = true; break;
	case FWHITE: c = WHITE; changed = true; break;
	case FGREEN: c = DARKGREEN; changed = true; break;
	default: break;
	}

	pOut->ClearStatusBar();
}

void ChngFillColor::Execute()
{
	ReadActionParameters();
	if (changed){

		if (pManager->getSelectedFig())
			pManager->getSelectedFig()->ChngFillClr(c);

		UI.FillColor = c;
		UI.Filled = true;
	}
}