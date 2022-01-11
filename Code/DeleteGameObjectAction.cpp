#include "DeleteGameObjectAction.h"
#include "GameObject.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) :Action(pApp) {

}
DeleteGameObjectAction::~DeleteGameObjectAction() {

}
void DeleteGameObjectAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	bool deleted = pGrid->RemoveObjectFromCell(GameObjectPosition);
	//update interface
	pGrid->UpdateInterface();

	if (!deleted) {
		pGrid->PrintErrorMessage("There is no GameObject here Click to continue");
	}
	else {
		pOut->PrintMessage("GameObject deleted successfully Click to continue");
		pIn->GetCellClicked();
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}
void DeleteGameObjectAction::ReadActionParameters() {
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the cell with the game object to delete");
	GameObjectPosition = pIn->GetCellClicked();

}