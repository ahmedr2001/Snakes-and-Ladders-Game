#include "AddCardAction.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member
	int x = 0; int y = 0;
	pOut->PrintMessage("Enter the card number from 1 to 12 .....");
	cardNumber = pIn->GetInteger(pOut);
	if (cardNumber < 1 || cardNumber>12)
	{
		pGrid->PrintErrorMessage("Invalid Card number,click to continue!");
	}
	else
	{
		do {
			pOut->PrintMessage("Click on an empty cell to put card " + to_string(cardNumber) + " on");
			cardPosition = pIn->GetCellClicked(); //getting cell to add card in
		} while (cardPosition.IsValidCell() != true);
	}
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	// 4- Make the needed validations on the read parameters
	if (cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99) {
		pGrid->PrintErrorMessage("Invalid Positions");
		cardPosition.SetHCell(0);
		cardPosition.SetVCell(0);
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber) //adding card depending on card number taken from user 
	{
		// A- Add the remaining cases
	case 1:
		pCard = new CardOne(cardPosition);
		break;

	case 2:
		pCard = new CardTwo(cardPosition);
		break;

	case 3:
		pCard = new CardThree(cardPosition);
		break;

	case 4:
		pCard = new CardFour(cardPosition);
		break;

	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid); //need check because not all cardes have read parameter
		// C- Add the card object to the GameObject of its Cell:
		bool done=pGrid->AddObjectToCell(pCard);
		
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!done)
		{
			pGrid->PrintErrorMessage("Invalid position,click to continue!");
		}
	}
	
	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
