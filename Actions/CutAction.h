#ifndef CUT_ACTION_H
#define CUT_ACTION_H

#include "Action.h"

class CutAction: public Action
{
private:
	Point P1;
public:
	CutAction(ApplicationManager*);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute();

};

#endif