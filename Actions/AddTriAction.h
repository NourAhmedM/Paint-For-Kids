#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"

class addTriAction:public Action
{
	Point P1,P2,P3;
	GfxInfo TriGfxInfo;
public:
	addTriAction(ApplicationManager *pApp);
	
	//Reads Triangle parameters
	virtual void ReadActionParameters();
	
	//Add triangle to the ApplicationManager
	virtual void Execute();
	
};

#endif