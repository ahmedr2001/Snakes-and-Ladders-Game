#include "CardTen.h"

Player* CardTen::card10owner;
bool CardTen::done = false;
int CardTen::CardPrice;
int CardTen::Fees;

CardTen::CardTen(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number (1 here)
	card10owner = NULL;
}

void CardTen::setowner(Player* p)
{
	card10owner = p;
	p->SetOwnership(1, CardPrice);
}

CardTen::~CardTen(void)
{
}

void CardTen::nullowner()
{
	card10owner = NULL;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//card10owner = pGrid->GetCurrentPlayer();
	// 2- Read an Integer from the user using the Input class and set the parameters with it
	if (done == false)
	{
		pOut->PrintMessage("New Card 10: Enter its Price ...");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Card 10: Enter its Fees ...");
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

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (card10owner == NULL)
	{
		pOut->PrintMessage("Do you want to buy those cells with cardnumber 10 it's price is " + to_string(CardPrice) + ",it's Fees is " + to_string(Fees) + "   1-yes   2-no");
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
				pGrid->PrintErrorMessage("Now, you are the owner of card " + to_string(cardNumber) + "!");
				card10owner->SetWallet(card10owner->GetWallet() - CardPrice);
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
		pGrid->PrintErrorMessage("Decrementing your wallet by " + to_string(Fees) + " to the owner player " + to_string(card10owner->GetPlayerNum()) + ",click to continue!");
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
		card10owner->SetWallet(card10owner->GetWallet() + Fees);
		return;
	}

}

void CardTen::Save(ofstream& outFile, int Type)
{
	if (Type == 2) { // number 2 representing cards
		Card::Save(outFile, Type);
		outFile << " " << CardPrice << " " << Fees << endl; //writing in save file which is .txt
	}
}

void CardTen::Open(ifstream& inFile)
{
	Card::Open(inFile);
	inFile >> CardPrice >> Fees; //load data from .txt
}

Card* CardTen::getCopy() {
	return new CardTen(*this); // using copy constructor to get the copy
}