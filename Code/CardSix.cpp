#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos)
	: Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		do
		{
			pOut->PrintMessage("Please enter X coordinate of destination cell (not current cell) between 0 and 10 (inclusive): ");
			XdestinationCell = pIn->GetInteger(pOut);
		} while (XdestinationCell < 0 || XdestinationCell > 10);

		do
		{
			pOut->PrintMessage("Please enter Y coordinate of destination cell (not current cell) between 0 and 8 (inclusive): ");
			YdestinationCell = pIn->GetInteger(pOut);
		} while (YdestinationCell < 0 || YdestinationCell > 8);
	} while (position.HCell() == XdestinationCell && position.VCell() == YdestinationCell);
}


void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Cell DestinationCell(YdestinationCell, XdestinationCell);
	CellPosition DestinationPosition(YdestinationCell, XdestinationCell);
	pGrid->UpdatePlayerCell(pPlayer, DestinationCell.GetCellPosition());
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Moving Player " + to_string(pPlayer->GetPlayerNum()) + " to cell number " + to_string(DestinationPosition.GetCellNum()));
	GameObject* obj = pGrid->GetGameObject(DestinationPosition);
	if (obj) {
		  
		obj->Apply(pGrid, pPlayer);
	}
}


CardSix::~CardSix()
{

}

void CardSix::Save(ofstream& outFile, int Type)
{
	if (Type == 2) {
		Card::Save(outFile, Type);
		outFile << " " << XdestinationCell << " " << YdestinationCell << endl;
	}
}

void CardSix::Open(ifstream& inFile)
{
	Card::Open(inFile);
	inFile >> XdestinationCell >> YdestinationCell;
}

Card* CardSix::getCopy() {
	return new CardSix(*this);
}