#include "LoadAction.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CLine.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

color StringToColor(string S);


LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut =pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please enter the File`s name.");
	S=pIn->GetSrting(pOut);
}

void LoadAction::Execute()
{
	Output* pOut =pManager->GetOutput();

	ReadActionParameters();
	pOut->ClearDrawArea();

	ifstream File(S+".txt");

	if (File.is_open())
	{
		pManager->setID(0);

		string UDc,UFc;

		File >> UDc >>UFc;

		UI.DrawColor=StringToColor(UDc);

		if(UFc=="NO_FILL")
			UI.Filled=false;

		else {
			UI.FillColor=StringToColor(UFc);
			UI.Filled = true;
		}

		pManager->DeleteAll();

		int Fcount;
		File>>Fcount;

		CFigure* TempFig;	
		string type;

		int tempID;
		int MaxID = 0;

		for (int i=0; i<Fcount;i++)
		{
			File >> type;
			if (type == "RECT")
				TempFig=new CRectangle;

			else if (type == "TRIANG")
				TempFig=new CTriangle;

			else if (type == "CIRCLE")
				TempFig=new CCircle;

			else	//i.e type i= line
				TempFig=new CLine;

			TempFig->Load(File);
			tempID = TempFig->getID();
			pManager->setID(tempID-1);
			if (MaxID < tempID)
				MaxID = tempID;
			pManager->AddFigure(TempFig);

		}

		pManager->setID(MaxID);
		pOut->ClearStatusBar();

		pOut->PrintMessage("File loaded. Have Fun :)");
	}

	else
		pOut->PrintMessage("There is no File with that name!");
}