#include "SaveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <fstream>

string GetColorName(color c);

char Errors [9]= {'*', '<', '>', '/', '\\', ':', '?', '"', '|'};

SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please enter the File's name. ");

	size_t found;

	do{

		S = pIn->GetSrting(pOut);

		for (int i = 0; i<9; i++){
			//Checking whether there's unvalid character or not
			found = S.find(Errors[i]);
			if (found != string::npos){
				pOut->PrintMessage("Name error. You can't enter that name. Try Another name, please.");
				break;
			}
		}

		if (S=="")
			S="Default";


	} while (found != string::npos);

	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();

	ofstream File;

	File.open(S+".txt");

	Output* pOut = pManager->GetOutput();

	File <<GetColorName(UI.DrawColor)<<"\t" <<GetColorName(UI.FillColor)<<endl;

	File <<pManager->getFigCount()<<endl;

	pManager->SaveAll(File);
	pOut->PrintMessage("File Saved.");
	File.close();
}