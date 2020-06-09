#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H



#include "Action.h"
class LoadAction : public Action
{
	string S;
public:
	LoadAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif