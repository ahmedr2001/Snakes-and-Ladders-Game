#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"


AddSnakeAction::AddSnakeAction(ApplicationManager* pApp):Action(pApp) {

}

void AddSnakeAction::Execute() {
	ReadActionParameters();

	Snake* pSnake = new Snake(startPos,endPos);
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}
void AddSnakeAction::ReadActionParameters() {
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	Snake* InputSnake = new Snake(startPos, endPos);
	//Doing the validations for the snake
	bool Valid = true;
	if ((startPos.GetCellNum() == 1)) {
		pGrid->PrintErrorMessage("Cannot put any Game object on the first cell");
		Valid = false;
	}
	else if ((startPos.GetCellNum() == 99)) {
		pGrid->PrintErrorMessage("Cannot put any Game Object on the last cell");
		Valid = false;
	}
	else if (startPos.HCell() != endPos.HCell()) {
		pGrid->PrintErrorMessage("The Snake can be vertical only!");
		Valid = false;
	}
	else if (startPos.VCell() >= endPos.VCell()) {
		pGrid->PrintErrorMessage("The Snake can be positioned to down only !");
		Valid = false;
	}
	GameError SnakeError = pGrid->IsOverLappingGrid(InputSnake);
	if (SnakeError == Overlapping) {
		pGrid->PrintErrorMessage("Snakes can't be overlapping!");
		Valid = false;
	}
	else if (SnakeError == SnakeAtEndOfLadder) {
		pGrid->PrintErrorMessage("Snakes can't be put at end of ladders!");
		Valid = false;
	}
	if (!Valid) {
		endPos.SetHCell(0);
		endPos.SetVCell(0);
		startPos.SetVCell(0);
		endPos.SetHCell(0);
	}
	delete InputSnake;

	// Clear messages
	pOut->ClearStatusBar();
}
AddSnakeAction::~AddSnakeAction() {

}