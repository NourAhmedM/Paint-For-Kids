#include "ChngDrawColor.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngDrawColor::ChngDrawColor(ApplicationManager *pApp): Action(pApp){ c = pApp->GetOutput()->getCrntDrawColor(); }

void ChngDrawColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ActionType Act;

	pOut->PrintMessage("Please choose a color");

	Act = pIn->GetUserAction();
	switch (Act){
	case FRED: c = RED; break;
	case FBLUE: c = BLUE; break;
	case FBLACK: c = BLACK; break;
	case FWHITE: c = WHITE; break;
	case FGREEN: c = DARKGREEN; break;
	default: break;
	}

	pOut->ClearStatusBar();
}

void ChngDrawColor::Execute()
{
	ReadActionParameters();
	if (pManager->getSelectedFig()){
		pManager->getSelectedFig()->ChngDrawClr(c);
		UI.DrawColor = c;
	}
	else
		UI.DrawColor = c;
}