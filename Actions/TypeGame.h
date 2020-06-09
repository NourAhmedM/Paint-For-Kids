#ifndef TYPE_GAME
#define TYPE_GAME

#include "Action.h"

class TypeGame:public Action
{
	Point Pnew;
	int stop;

public:
	TypeGame(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif