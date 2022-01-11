#include "Ladder.h"
#include "Player.h"
#include "Card.h"
#include "Snake.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a Ladder. Click to continue ..." and wait mouse click

	// 2- Apply the Ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("You have reached a Ladder. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	if (Card* pCard=dynamic_cast<Card*>(pGrid->GetGameObject(endCellPos)))
	{
		pCard->Apply(pGrid,pPlayer);
	}
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& outFile, int Type)
{
	int startCellNum = position.GetCellNum();
	int endCellNum = endCellPos.GetCellNum();
	if (Type != 0)
		return;
	else {
		outFile << startCellNum << " " << endCellNum << endl;
	}
}

void Ladder::Open(ifstream& inFile)
{
	int startCellNum, endCellNum;
	inFile >> startCellNum >> endCellNum;
	CellPosition pos(startCellNum);
	CellPosition pos2(endCellNum);
	position = pos;
	endCellPos = pos2;
}

GameError Ladder::IsOverLapping(GameObject* NewGameObject) const {
	Snake* NewSnake = dynamic_cast<Snake*>(NewGameObject);
	if (NewSnake) {
		if (NewSnake->GetPosition().GetCellNum() == endCellPos.GetCellNum()) return SnakeAtEndOfLadder;
	}
	Ladder* NewLadder = dynamic_cast<Ladder*>(NewGameObject);
	if (!NewLadder) return NoError;

		CellPosition StartOfNewLadder = NewLadder->GetPosition();
		CellPosition EndOfNewLadder = NewLadder->endCellPos;

		CellPosition StartOfCurrentLadder = position.GetCellNum();
		CellPosition EndOfCurrentLadder = endCellPos.GetCellNum();

		//Check if they aren't in the same H
		if (StartOfNewLadder.HCell() != StartOfCurrentLadder.HCell()) {
			return NoError;
		}

		int NewLadderStart = StartOfNewLadder.VCell();
		int NewLadderEnd = EndOfNewLadder.VCell();
		int CurrentLadderStart = StartOfCurrentLadder.VCell();
		int CurrentLadderEnd = EndOfCurrentLadder.VCell();


		if (NewLadderStart >= CurrentLadderEnd && NewLadderEnd <= CurrentLadderStart) {
			return Overlapping;
		}
		return NoError;
	
}


bool Ladder::IsValid()
{
	if (position.GetCellNum() == 1)
		return false;
	if (position.GetCellNum() == 99)
		return false;
	if (position.HCell() != endCellPos.HCell())
		return false;
	if (position.VCell() <= endCellPos.VCell())
		return false;
	return true;
}


Ladder::~Ladder()
{
}
