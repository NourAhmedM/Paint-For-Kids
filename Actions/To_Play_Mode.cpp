#include "To_Play_Mode.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"

PlayModeAction::PlayModeAction(ApplicationManager *pApp):Action(pApp)
{}

void PlayModeAction::ReadActionParameters()
{}

void PlayModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();

	pOut->CreatePlayToolBar();

	UI.InterfaceMode=MODE_PLAY;

}