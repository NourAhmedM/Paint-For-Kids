#include "ColorGame.h"

#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"

color StringToColor(string S);
string GetColorName(color c);

ColorGame::ColorGame(ApplicationManager *pApp):Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("You Choosed Pick And Hide Game By Color. GooD Luck To Finish It. Click Anywhere To Continue");
	
	pManager->UpdateInterface();
	
	Point P;
	pIn->GetPointClicked(P.x,P.y);

	pOut->ClearStatusBar();
	stop=0;
}

void ColorGame::ReadActionParameters()
{
	ActionType Act;
	Input* pIn = pManager->GetInput();

	Act=pIn->GetUserAction(Pcolor.x,Pcolor.y,false);

	switch (Act){

	case TYPE:
		pManager->ReSet();
		pManager->ExecuteAction(Act);
		stop++;
		break;	//because we are already in Type there is error when he execute the Type so we have to Regroupall again before Execute Type Again!!
	

	case COLOR:
		pManager->ReSet();
		pManager->ExecuteAction(Act);
		stop++;
		break;
	
	
	case TYPE_N_COLOR:
		pManager->ReSet();
		pManager->ExecuteAction(Act);
		stop++;
		break;


	case TO_DRAW:
		pManager->ExecuteAction(Act);
		stop++;
		break;


	case EXIT:
		pManager->ExecuteAction(Act);
		stop++;
		throw "EXIT";
		break;

	default: break;
	}

}


void ColorGame::Execute()
{
	pManager->ReSet();
	int win = 0, loss = 0, CorrectNumber;

	CFigure* Random=pManager->GetRandomFigure(COLOR);
	CFigure* Choosen;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if(Random==NULL)
		pOut->PrintMessage("You Didnt Draw Any Colored Figure. Go To DrawMode And Draw Some. Hurry! :)");
	else 
	{
		CorrectNumber = pManager->RandomFigureCount(COLOR,Random);
		pOut->PrintMessage("You Should Choose All "+GetColorName(Random->GetColor())+"  Shapes. Good Luck! xD");

		while(win<CorrectNumber)
		{
			pIn->GetPointClicked(Pcolor.x,Pcolor.y);

			try{
				ReadActionParameters();
			}
			catch (char*){ //That's cuz if we clicked on EXIT during the game, we should terminate the program
				throw "EXIT";
			}

			if(stop!=0)
			{
				pManager->ReSet();
				return;
			}

			Choosen=pManager->GetFigure(Pcolor.x,Pcolor.y);

			if(Choosen!=NULL)
			{
				if(Choosen->GetColor()==Random->GetColor())
				{
					win++;
					Choosen->SetChoosed();
				}
				else 
				{
					loss++;
					Choosen->SetChoosed();
				}
				pManager->UpdateInterface();
				pOut->PrintMessage("Win= "+to_string(win)+" Loss= "+to_string(loss));	//here continous grade
			}
		}

		pOut->PrintMessage("Congratz!!!! You Finished The Game. Your Grades = "+to_string(win)+"/"+to_string(win+loss)+". Click Anywhere To Continue");
		
		Point Nothing;
		pIn->GetPointClicked(Nothing.x,Nothing.y);
		pOut->ClearStatusBar();
		pManager->ReSet();
	}
}


