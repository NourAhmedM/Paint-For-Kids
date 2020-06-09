#ifndef COLOR_GAME
#define COLOR_GAME

#include "Action.h"

class ColorGame:public Action
{
	Point Pcolor;
	int stop;
public:
	ColorGame(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
