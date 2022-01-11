#include "CardThree.h"
#include "ApplicationManager.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- give the pPlayer an extra dice roll
	pGrid->PrintErrorMessage("You have landed on Card 3, you now have an extra dice roll!");
	//giving player an additional dice roll 
	for (int i = 0; i < 3; i++) {
		pGrid->AdvanceCurrentPlayer();
	}
}

void CardThree::Save(ofstream& outFile, int Type)
{
	if (Type == 2){ // number 2 representing cards
		Card::Save(outFile, Type);
		outFile << endl; //writing in save file which is .txt
	}
}

Card* CardThree::getCopy() {
	return new CardThree(*this); // using copy constructor to get the copy
}

void CardThree::Open(ifstream& inFile)
{
	Card::Open(inFile); //load data from .txt
}
