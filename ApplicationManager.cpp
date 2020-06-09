#include "ApplicationManager.h"

#include "Actions\AddCircAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"

#include "Actions\ChngDrawColor.h"
#include "Actions\ChngFillColor.h"

#include "Actions\CopyAction.h"
#include "Actions\CutAction.h"
#include "Actions\PasteAction.h"
#include "Actions\LoadAction.h"
#include "Actions\SaveAction.h"
#include <fstream>

#include "Actions\DelAction.h"
#include "Actions\SelectAction.h"
#include "Actions\ExitAction.h"

#include "Actions\To_Draw_Mode.h"
#include"Actions\To_Play_Mode.h"
#include"Actions\TypeGame.h"
#include"Actions\ColorGame.h"
#include"Actions\Type_Color_Game.h"

#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "Figures\CLine.h"
#include "Figures\CCircle.h"
#include "Figures\CTriangle.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	ID = 0;

	SelectedFig = NULL;
	Clipboard = NULL;


	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType &ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;

	case DRAW_TRI:
		pAct = new addTriAction(this);
		break;

	case FRED:
		pOut->PrintMessage("Please Choose first either Draw or Fill Color icon fisrt :)");
		break;

	case FBLUE:
		pOut->PrintMessage("Please Choose first either Draw or Fill Color icon fisrt :)");
		break;

	case FGREEN:
		pOut->PrintMessage("Please Choose first either Draw or Fill Color icon fisrt :)");
		break;

	case FBLACK:
		pOut->PrintMessage("Please Choose first either Draw or Fill Color icon fisrt :)");
		break;

	case FWHITE:
		pOut->PrintMessage("Please Choose first either Draw or Fill Color icon fisrt :)");
		break;

	case COPY:
		pAct= new CopyAction(this);
		break;

	case CUT:
		pAct= new CutAction(this);
		break;

	case PASTE:
		pAct= new PasteAction(this);
		break;

	case DEL:
		pAct = new DelAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;

	case SELECT:
		pAct = new SelectAction(this);
		break;

	case CHNG_DRAW_CLR:
		pAct = new ChngDrawColor(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChngFillColor(this);
		break;

	case TO_PLAY:
		pAct=new PlayModeAction(this);
		break;

	case TO_DRAW:
		pAct=new DrawModeAction(this);
		break;

	case TYPE:
		pAct=new TypeGame(this);
		break;
	case COLOR:
		pAct=new ColorGame(this);
		break;
	case TYPE_N_COLOR:
		pAct=new Type_Color_Game(this);
		break;
	}

	//Execute the created action
	if(pAct != NULL)
	{
		try{
			pAct->Execute();//Execute
		}
		catch (char*){
			ActType = EXIT;
		}
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

void ApplicationManager::ReSet()// The Function Regroup The Deleted list with the Figure List and sets all figures to not choosed again
{
	for(int i=0;i<FigCount;i++)
	{
		FigList[i]->SetChoosed(false);
	}

	UpdateInterface();
}

void ApplicationManager::SaveAll(ofstream & out)
{
	for (int i=0; i<FigCount;i++)
	{
		FigList[i]->Save(out);
	}
}

void ApplicationManager::DeleteAll()
{
	for (int i=0;i<FigCount;i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount=0;
}

void ApplicationManager::setID(int Fcount)
{
	ID = Fcount;
}

//This function deletes the sleceted figure //old name:UpdateFigList
void ApplicationManager::DeleteSelectedFigure(){

	int index = getSelectedFigInd();

	if (index != -1){
		SelectedFig = NULL;

		for (int i = index; i<FigCount; i++)
			FigList[i] = FigList[i+1];

		delete FigList[FigCount];
		FigList[FigCount] = NULL;
		FigCount--;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount] = pFig;
		FigList[FigCount++]->setID(++ID);
	}
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount-1; i>= 0; i--){
		if (FigList[i]->inSegment(x, y))
			if(!FigList[i]->IsChoosed())
				return FigList[i];
	}
	return NULL;
}

int ApplicationManager::getFigCount() const
{
	return FigCount;
}

CFigure* ApplicationManager::GetRandomFigure(ActionType act) const
{

	CFigure* RandomFig;
	int randomindex;
	if(act==TYPE)
	{
		if(FigCount==0)
			return NULL;
		randomindex=rand()%FigCount;
		RandomFig=FigList[randomindex];
		return RandomFig;
	}
	if(act==COLOR)
	{
		if(FigCount==0)
			return NULL;
		int i;
		for( i=0;i<FigCount;i++)
			if(FigList[i]->IsFilled()==true)
				break;
		if(i==FigCount)		//this means that there is no Filled shape in the Figlist
			return NULL;
		bool b=true;

		do			//this block is only done to make sure that the random Fig is Filled
		{
			randomindex=rand()%FigCount;
			RandomFig=FigList[randomindex];
			if(FigList[randomindex]->IsFilled())
				b=false;
		}
		while(b);

		return RandomFig;
	}
	if(act=TYPE_N_COLOR)
	{
		if(FigCount==0)
			return NULL;
		int i;
		for( i=0;i<FigCount;i++)
			if(FigList[i]->IsFilled()==true)
				break;
		if(i==FigCount)		//this means that there is no Filled shape in the Figlist
			return NULL;
		bool b=true;

		do				//this block is only done to make sure that the random Fig is Filled
		{
			randomindex=rand()%FigCount;
			RandomFig=FigList[randomindex];
			if(FigList[randomindex]->IsFilled())
				b=false;
		}
		while(b);

		return RandomFig;
	}
	return NULL;
}

void ApplicationManager::setSelectedFig(CFigure *p){
	SelectedFig = p;
}

CFigure *ApplicationManager::getSelectedFig() const { return SelectedFig; }

int ApplicationManager::getSelectedFigInd() const
{
	for (int i = 0; i<FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}

void ApplicationManager:: SetClipboard(CFigure* f)
{
	if (Clipboard==NULL)
		Clipboard = f;
	else
	{
		delete Clipboard;
		Clipboard=f;
	}
}

CFigure * ApplicationManager:: GetClipboard()const
{
	return Clipboard;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if(!(FigList[i]->IsChoosed()))
			FigList[i]->Draw(pOut);
}


int ApplicationManager:: RandomFigureCount(ActionType act,CFigure* Rand)
{
	int Nu=0;
	if(act==TYPE)
	{
		for(int i=0;i<FigCount;i++)
			if(FigList[i]->GetType()==Rand->GetType())
				Nu++;
		return Nu;
	}
	if(act==COLOR)
	{
		for(int j=0;j<FigCount;j++)
			if(FigList[j]->GetColor()==Rand->GetColor())
				Nu++;

		return Nu;
	}
	if(act==TYPE_N_COLOR)
	{
		for(int j=0;j<FigCount;j++)
			if(FigList[j]->GetColor()==Rand->GetColor()&&FigList[j]->GetType()==Rand->GetType())
				Nu++;
		return Nu;
	}
	return Nu;
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	if (Clipboard!=NULL)
		delete Clipboard;

}
