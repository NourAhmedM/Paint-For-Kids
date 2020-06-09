#include "Type_Color_Game.h"

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

Type_Color_Game::Type_Color_Game(ApplicationManager *pApp):Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("You Choosed Pick And Hide Game By Type And Color. GooD Luck To Finish It. Click Anywhere To Continue");

	pManager->UpdateInterface();

	Point P;

	pIn->GetPointClicked(P.x,P.y);

	pOut->ClearStatusBar();

	stop=0;
}


void Type_Color_Game::ReadActionParameters()
{
	ActionType Act;
	Input* pIn = pManager->GetInput();
	Act=pIn->GetUserAction(Ptc.x,Ptc.y,false);

	switch (Act){

	case TYPE:
		pManager->ReSet();
		pManager->ExecuteAction(Act);
		stop++;
		break;// because we are already in Type there is error when he execute the Type so we have to Regroupall again before Execute Type Again!!

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
		throw "EXIT";
		stop++;
		break;

	default: break;

	}

}



void Type_Color_Game::Execute()
{

	pManager->ReSet();

	int win=0, loss=0, CorrectNumber;

	CFigure* Random=pManager->GetRandomFigure(TYPE_N_COLOR);
	CFigure* Choosen;

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if(Random==NULL)
		pOut->PrintMessage("You Didnt Draw Any Colored Figures. Go To DrawMode And Draw Some. Hurry! :)");

	else 
	{
		CorrectNumber=pManager->RandomFigureCount(TYPE_N_COLOR,Random);
		pOut->PrintMessage("You Should Choose All "+GetColorName(Random->GetColor())+" "+Random->GetType()+" Shapes. Good Luck! xD");

		while(win<CorrectNumber)
		{
			pIn->GetPointClicked(Ptc.x,Ptc.y);
			try{
				ReadActionParameters();
			}
			catch (char*){
				throw "EXIT";
			}


			if(stop!=0)
			{
				pManager->ReSet();
				return;
			}

			Choosen=pManager->GetFigure(Ptc.x,Ptc.y);

			if(Choosen!=NULL)
			{
				if(Choosen->GetType()==Random->GetType()&&Choosen->GetColor()==Random->GetColor())
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

				pOut->PrintMessage("Win= "+to_string(win)+" Loss= "+to_string(loss));//here continous grade
			}
		}

		pOut->PrintMessage("Congratz!!!! You Fineshed The Game. Your Grades = "+to_string(win)+"/"+to_string(win+loss)+". Click Anywhere To Continue");

		Point Nothing;

		pIn->GetPointClicked(Nothing.x,Nothing.y);
		pOut->ClearStatusBar();
		pManager->ReSet();
	}

}
