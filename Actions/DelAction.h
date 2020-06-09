#ifndef DEL_ACTION_H
#define DEL_ACTION_H

#include "Action.h"

class DelAction : public Action
{
public:
	DelAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif