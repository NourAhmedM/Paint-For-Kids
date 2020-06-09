#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "Action.h"

class PasteAction: public Action{
	Point  p1;

public:
	PasteAction(ApplicationManager*);

	virtual void ReadActionParameters();
	
	virtual void Execute();


};

#endif