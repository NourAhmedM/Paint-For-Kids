#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H


#include "Action.h"

class SaveAction : public Action
{
	string S;

public:
	
	SaveAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif