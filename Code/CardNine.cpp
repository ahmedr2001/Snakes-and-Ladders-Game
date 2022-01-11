#include "CardNine.h"

Player* CardNine::card9owner;
bool CardNine::done=false;
int CardNine::CardPrice;
int CardNine::Fees;

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number
	card9owner = NULL;
}

void CardNine::setowner(Player* p)
{
	card9owner = p;
	p->SetOwnership(0, CardPrice);
}

void CardNine::nullowner()
{
	card9owner = NULL;
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the parameters with it
	if (done==false)
	{
		pOut->PrintMessage("New Card 9: Enter its Price ...");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Card 9: Enter its Fees ...");
		Fees = pIn->GetInteger(pOut);
		done = true;
	}
	else
	{
	
	}

	// [ Note ]:
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (card9owner ==NULL) //check if card 9 has no owner
	{
		pOut->PrintMessage("Do you want to buy those cells with cardnumber 9 it's price is "+ to_string(CardPrice)+",it's Fees is "+ to_string(Fees) + "   1-yes   2-no");
		int choise = pIn->GetInteger(pOut);
		if (choise == 2)
		{
			return;
		}
		if (choise == 1)
		{
			if (pPlayer->GetWallet() >= CardPrice)
			{
				setowner(pPlayer);
				pGrid->PrintErrorMessage("Now, you are the owner of card "+to_string(cardNumber)+"!");
				card9owner->SetWallet(card9owner->GetWallet() - CardPrice);
				// apply owner for all cards not this only -> static
			}
			else
			{
				pGrid->PrintErrorMessage("you donot have enough money in your wallet");
				return;
			}
		}
	}
	else
	{
		pGrid->PrintErrorMessage("Decrementing your wallet by " + to_string(Fees) +" to the owner player "+ to_string(card9owner->GetPlayerNum())+ ",click to continue!");
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
		card9owner->SetWallet(card9owner->GetWallet() + Fees);
		return;
	}
	
}

void CardNine::Save(ofstream& outFile, int Type)
{
	if (Type == 2) { // number 2 representing cards
		Card::Save(outFile, Type);
		outFile << " " << CardPrice << " " << Fees << endl; //writing in save file which is .txt
	}
}

void CardNine::Open(ifstream& inFile)
{
	Card::Open(inFile);
		inFile >> CardPrice >> Fees; //load data from .txt
	
}

Card* CardNine::getCopy() {
	return new CardNine(*this); // using copy constructor to get the copy
}