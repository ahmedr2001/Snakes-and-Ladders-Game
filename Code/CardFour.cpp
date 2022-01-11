#include "CardFour.h"

bool CardFour::Card4Players[MaxPlayerCount];

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- prevent the pPlayer from the next dice roll
	pGrid->PrintErrorMessage("You have landed on Card 4, you are prevented from rolling the next turn!");
	//get player number
	int playerNum = pPlayer->GetPlayerNum();
	// make him a card 4 affected player
	pPlayer->SetCardFourEffect(1);
	Card4Players[playerNum] = true;
	// make player not free to roll next roll dice
	Freed = false;
}

bool CardFour::isCard4Players(int playerNum) const //return if player is card4 affected or not
{
	return Card4Players[playerNum];
}

bool CardFour::isfree() const{ //return if player is free or not
	return Freed;
}

void CardFour::free(int playerNum) //free the player and make him not card 4 affected
{
	Freed = true;
	Card4Players[playerNum] = false;
}

void CardFour::Save(ofstream& outFile, int Type)
{
	if (Type == 2){ // number 2 representing cards
		Card::Save(outFile, Type);
		outFile << endl; //writing in save file which is .txt
	}
}

Card* CardFour::getCopy() {
	return new CardFour(*this); // using copy constructor to get the copy
}

void CardFour::Open(ifstream& inFile)
{
	Card::Open(inFile); //load data from .txt
}
