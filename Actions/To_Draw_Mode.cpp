#include "To_Draw_Mode.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"


DrawModeAction::DrawModeAction(ApplicationManager *pApp):Action(pApp)
{}

void DrawModeAction::ReadActionParameters()
{}

void DrawModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearToolBar();

	pOut->CreateDrawToolBar();

	UI.InterfaceMode=MODE_DRAW;

}


