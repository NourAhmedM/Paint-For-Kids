#include "ExitAction.h"
#include "SaveAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ExitAction:: ExitAction(ApplicationManager *pApp): Action(pApp){}

void ExitAction::ReadActionParameters(){}

void ExitAction::Execute(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Do you want to save your file first? Enter 'yes' if so, anything else otherwise.");
	string s;
	s = pIn->GetSrting(pOut);
	if (s == "yes"){
		ActionType Act = SAVE;
		pManager->ExecuteAction(Act);
	}
	else
		pOut->PrintMessage("Adios, mi amigo!");

}