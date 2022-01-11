#include "SwitchToPlayModeAction.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToPlayModeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->CreatePlayModeToolBar();
}

void SwitchToPlayModeAction::Execute()
{
	ReadActionParameters();
	
	
}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{

}