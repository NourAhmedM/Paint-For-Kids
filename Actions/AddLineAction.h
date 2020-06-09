#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"

class AddLineAction : public Action{
	Point start, end;
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	
	//Add Line to the ApplicationManager
	virtual void Execute() ;
};

#endif