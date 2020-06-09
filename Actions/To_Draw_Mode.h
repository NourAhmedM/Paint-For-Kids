#ifndef TO_DRAW_MODE
#define TO_DRAW_MODE

#include "Action.h"

class DrawModeAction :public Action
{
public:
	DrawModeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif