#ifndef CHNG_FILL_COLOR_H
#define CHNG_FILL_COLOR_H

#include "Action.h"

class ChngFillColor: public Action {
	color c;
	bool changed;	//to check if I clicked on a color on the toolbar or anywhere else. It fixes some bugs in the program
public:
	ChngFillColor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif