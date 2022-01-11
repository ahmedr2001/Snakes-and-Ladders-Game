#include "CardFive.h"





CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int diceNumber = pPlayer->GetJustRolledDiceNum();
	CellPosition destination = pPlayer->GetCell()->GetCellPosition();
	destination.AddCellNum(-1 * diceNumber);
	pPlayer->SetStepCount(destination.GetCellNum());
	pGrid->PrintErrorMessage("Oops You will get back to the last position");
	pGrid->UpdatePlayerCell(pPlayer, destination);
	pGrid->UpdateInterface();
	Card* CardinCellDestination = pGrid->HasCard(destination);
	if (CardinCellDestination) {
		CardinCellDestination->Apply(pGrid, pPlayer);
	}
}

CardFive::~CardFive()
{
}

void CardFive::Save(ofstream& outFile, int Type)
{
	if (Type == 2) {
		Card::Save(outFile, Type);
		outFile << endl;
	}
}

void CardFive::Open(ifstream& inFile)
{
	Card::Open(inFile);
}

Card* CardFive::getCopy() {
	return new CardFive(*this);
}
