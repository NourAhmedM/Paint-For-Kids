#ifndef TYPE_COLOR_GAME
#define TYPE_COLOR_GAME

#include "Action.h"

class Type_Color_Game:public Action
{
	Point Ptc;
	int stop;
public:
	Type_Color_Game(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
