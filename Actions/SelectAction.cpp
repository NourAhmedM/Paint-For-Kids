#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager *pApp): Action(pApp) {}

void SelectAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please select a figure");

	pIn->GetPointClicked(SelectedPoint.x, SelectedPoint.y);
	pOut->ClearStatusBar();
}

void SelectAction::Execute(){
	ReadActionParameters();
	select(SelectedPoint);
}

void SelectAction::select(Point p){
	CFigure* pointer = pManager->GetFigure(p.x, p.y);

	if (pointer != NULL){
		if (pointer->IsSelected()){
			pointer->SetSelected(false);
			pManager->setSelectedFig(NULL);
		}

		else{
			if (pManager->getSelectedFig())
				pManager->getSelectedFig()->SetSelected(false);
			pointer->SetSelected(true);
			pointer->PrintInfo( pManager->GetOutput());
			pManager->setSelectedFig(pointer);
		}
	}
}