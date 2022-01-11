#include "SaveGridAction.h"
#include "Grid.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp)
	:Action(pApp)
{

}

SaveGridAction::~SaveGridAction()
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter the filename: ");
	fileName = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	ofstream outFile(fileName+".txt",ios::trunc);

	Grid* pGrid = pManager->GetGrid();
	int ladderCount = pGrid->GetNumOfObjects(0);
	int snakeCount = pGrid->GetNumOfObjects(1);
	int cardCount = pGrid->GetNumOfObjects(2);

	if (outFile.is_open())
	{
		outFile << ladderCount << endl;
		pGrid->SaveAll(outFile, 0);
		outFile << snakeCount << endl;
		pGrid->SaveAll(outFile, 1);
		outFile << cardCount << endl;
		pGrid->SaveAll(outFile, 2);
	}
	else
	{
		return;
	}
	
	
	outFile.close();
}