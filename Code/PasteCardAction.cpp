#include "PasteCardAction.h"
#include "CutCardAction.h"
#include "CopyCardAction.h"
#include "AddCardAction.h"
#include "ApplicationManager.h"
#include "Card.h"
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

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void PasteCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		pOut->PrintMessage("click on cell to paste the card to it ........");
		pastePosition = pIn->GetCellClicked(); // Read the CardCell parameter
	} while (pastePosition.IsValidCell() == false || pastePosition.GetCellNum() == 1 || pastePosition.GetCellNum() == 99 || pGrid->GetGameObject(pastePosition) != NULL); //checking cases where canot paste the card

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card *cCard = pGrid->GetClipboard();
	cardnum = cCard->GetCardNumber();
	if (cCard)
	{
		Card* pCard = NULL;
		switch (cardnum) //creating new card depending on card number taken from clipboard 
		{
		case 1:
			pCard = dynamic_cast<CardOne*>(cCard)->getCopy();
			break;
		case 2:
			pCard = dynamic_cast<CardTwo*>(cCard)->getCopy();
			break;
		case 3:
			pCard = dynamic_cast<CardThree*>(cCard)->getCopy();
			break;
		case 4:
			pCard = dynamic_cast<CardFour*>(cCard)->getCopy();
			break;
		case 5:
			pCard = dynamic_cast<CardFive*>(cCard)->getCopy();
			break;
		case 6:
			pCard = dynamic_cast<CardSix*>(cCard)->getCopy();
			break;
		case 7:
			pCard = dynamic_cast<CardSeven*>(cCard)->getCopy();
			break;
		case 8:
			pCard = dynamic_cast<CardEight*>(cCard)->getCopy();
			break;
		case 9:
			pCard = dynamic_cast<CardNine*>(cCard)->getCopy();
			break;
		case 10:
			pCard = dynamic_cast<CardTen*>(cCard)->getCopy();
			break;
		case 11:
			pCard = dynamic_cast<CardEleven*>(cCard)->getCopy();
			break;
		case 12:
			pCard = dynamic_cast<CardTwelve*>(cCard)->getCopy();
			break;
		}
		pCard->SetPosition(pastePosition); //changing position to new paste position
		pGrid->AddObjectToCell(pCard); //adding card to cell 
		//update interface
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("Successfully Card " + to_string(pCard->GetCardNumber()) + " was pasted ,click to continue!");
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot paste ,No card in clipboard ,click to continue!");
		return;
	}

	
}

void PasteCardAction::Save(ofstream& outFile, int Type)
{
		pCard->Save(outFile, 2); //writing in save file which is .txt
								 // number 2 representing cards
}


PasteCardAction::~PasteCardAction()
{
}
