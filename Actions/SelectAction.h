#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"

class SelectAction:public Action{
	Point SelectedPoint;
public:
	SelectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;

	void select(Point);

};

#endif