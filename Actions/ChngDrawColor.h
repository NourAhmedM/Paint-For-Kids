#ifndef CHNG_DRAW_COLOR_H
#define CHNG_DRAW_COLOR_H

#include "Action.h"

class ChngDrawColor: public Action {
	color c;
public:
	ChngDrawColor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif