#ifndef TO_PLAY_MODE
#define TO_PLAY_MODE

#include "Action.h"

class PlayModeAction :public Action
{
public:
	PlayModeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif