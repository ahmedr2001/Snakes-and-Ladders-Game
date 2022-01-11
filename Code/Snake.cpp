#include "Snake.h"
#include "Player.h"
#include "Ladder.h"
#include "GameObject.h"
#include "Card.h"



Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("You have reached a Snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	if (Card* pCard = dynamic_cast<Card*>(pGrid->GetGameObject(endCellPos)))
	{
		pCard->Apply(pGrid, pPlayer);
	}
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& outFile, int Type)
{
	int startCellNum = position.GetCellNum();
	int endCellNum = endCellPos.GetCellNum();
	if (Type != 1)
		return;
	else {
		outFile << startCellNum << " " << endCellNum << endl;
	}
}

void Snake::Open(ifstream& inFile)
{
	int startCellNum, endCellNum;
	inFile >> startCellNum >> endCellNum;

	position = position.GetCellPositionFromNum(startCellNum);
	endCellPos = endCellPos.GetCellPositionFromNum(endCellNum);
}
 GameError Snake::IsOverLapping(GameObject* NewGameObject) const{
	 Ladder* NewLadder = dynamic_cast<Ladder*>(NewGameObject);
	 if (NewLadder) {
		 if (NewLadder->GetPosition().GetCellNum() == endCellPos.GetCellNum()) return LadderAtEndofSnake;
	 }
	
	 Snake* NewSnake = dynamic_cast<Snake*> (NewGameObject);
	 //Ladder* NewLadder = dynamic_cast<Ladder*>(NewGameObject);
	 if (!NewSnake) return NoError;

	 CellPosition StartOfNewSnake = NewSnake->GetPosition();
	 CellPosition EndOfNewSnake = NewSnake->endCellPos;
	 
	 CellPosition StartOfCurrentSnake = position.GetCellNum();
	 CellPosition EndOfCurrentSnake = endCellPos.GetCellNum();
	 
	 //Check if they aren't in the same H
	 if (StartOfNewSnake.HCell() != StartOfCurrentSnake.HCell()) {
	  return NoError;
	 }
	 
	 int NewSnakeStart = StartOfNewSnake.VCell();
	 int NewSnakeEnd = EndOfNewSnake.VCell();
	 int CurrentSnakeStart = StartOfCurrentSnake.VCell();
	 int CurrentSnakeEnd = EndOfCurrentSnake.VCell();
	 
	 if (NewSnakeStart <= CurrentSnakeEnd && NewSnakeEnd >= CurrentSnakeStart) {
		return Overlapping;
	 }
	 return NoError;
}

 bool Snake::IsValid()
 {
	 if (position.GetCellNum() == 1)
		 return false;
	 if (position.GetCellNum() == 99)
		 return false;
	 if (position.HCell() != endCellPos.HCell())
		 return false;
	 if (position.VCell() >= endCellPos.VCell())
		 return false;
	 return true;
 }

Snake::~Snake()
{
}
