#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	Ladder *InputLadder = new Ladder(startPos, endPos);

	///TODO: Make the needed validations on the read parameters
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
		pGrid->PrintErrorMessage("The ladder can be vertical only!");
		Valid = false;
	}
	else if (startPos.VCell() <= endPos.VCell()) {
		pGrid->PrintErrorMessage("The Ladder can be positioned to up only !");
		Valid = false;
	}
	GameError LadderError = pGrid->IsOverLappingGrid(InputLadder);
	 if (LadderError == Overlapping ){
		pGrid->PrintErrorMessage("Ladders can't be overlapping!");
		Valid = false;
	 }
	 else if (LadderError == LadderAtEndofSnake) {
		 pGrid->PrintErrorMessage("Ladders can't be put at end of Snakes!");
		 Valid = false;
	}
	if (!Valid) {
		endPos.SetHCell(0);
		endPos.SetVCell(0);
		startPos.SetVCell(0);
		endPos.SetHCell(0);
	}
	delete InputLadder;

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
