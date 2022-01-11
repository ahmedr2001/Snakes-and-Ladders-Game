#include "SwitchToDesignModeAction.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToDesignModeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->CreateDesignModeToolBar();
	pOut->ClearStatusBar();
}

void SwitchToDesignModeAction::Execute()
{
	ReadActionParameters();


}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{

}