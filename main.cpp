#include "ApplicationManager.h"

color StringToColor(string S);
string GetColorName(color c);


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	} while (ActType != EXIT);
	

	
	return 0;
}

string GetColorName(color c)
{
	if (c==RED)
		return "RED";
	if (c==DARKGREEN)
		return "GREEN";
	if (c==WHITE)
		return "WHITE";
	if (c==BLACK)
		return "BLACK";
	if (c==BLUE)
		return "BLUE";
	return "NO_FILL";
}

color StringToColor(string S)
{
	if (S=="RED")
		return RED;
	if (S=="GREEN")
		return DARKGREEN;
	if (S=="WHITE")
		return WHITE;
	if (S=="BLACK")
		return BLACK;
	return BLUE;	//the only reminded color
}

