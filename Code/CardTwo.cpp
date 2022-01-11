#include "CardTwo.h"
#include "Ladder.h"
#include "Grid.h"
#include "Player.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	CellPosition CellPositionOfPlayer = pPlayer->GetCell()->GetCellPosition();
	Ladder* NextLadder = pGrid->GetNextLadder(CellPositionOfPlayer);
	
	if (NextLadder == NULL) {
		pGrid->PrintErrorMessage("No Next Ladder exists! The player will not move.");
	}
	else {
		pGrid->PrintErrorMessage("You have Card 2. You are lucky, You will go to the next Ladder Click to continue");
		//int MovesCount = NextLadder->GetPosition().GetCellNum() - pPlayer->GetCell()->GetCellPosition().GetCellNum();
		CellPosition LadderPosition = NextLadder->GetPosition();
		pGrid->UpdatePlayerCell(pPlayer,LadderPosition);
		NextLadder->Apply(pGrid,pPlayer);
	}

}

void CardTwo::Save(ofstream& outFile, int Type)
{
	if (Type == 2){
		Card::Save(outFile, Type);
		outFile << endl;
	}
}

Card* CardTwo::getCopy() {
	return new CardTwo(*this);
}

CardTwo::~CardTwo() {

}

void CardTwo::Open(ifstream& inFile)
{
	Card::Open(inFile);
}