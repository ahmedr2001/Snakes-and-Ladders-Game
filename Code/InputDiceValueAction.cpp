#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"
#include "CardEight.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp)
	: Action(pApp)
{

}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do
	{
		pOut->PrintMessage("Please enter a dice value between 1 and 6 (inclusive): ");
		inputDiceValue = pIn->GetInteger(pOut);
	} while (inputDiceValue < 1 || inputDiceValue > 6);
}

void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame()) {
		pGrid->GetOutput()->PrintMessage("game ended !");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pManager->ExecuteAction(EXITT);
	}
	else {
		Output* pOut = pGrid->GetOutput();
		Player* pPlayer = pGrid->GetCurrentPlayer();
		int playerNum = pPlayer->GetPlayerNum();
		Cell* pCell = pPlayer->GetCell();
		GameObject* pObj = pCell->GetGameObject();
		CardEight* pCardEight = dynamic_cast<CardEight*>(pObj);
		int prisonRemTurns = pPlayer->GetPrisonRemTurns();
		if (prisonRemTurns) {
			pCardEight->DecrementRemDays(playerNum);
			pPlayer->SetPrisonRemTurns(prisonRemTurns - 1);
			if (pPlayer->GetPrisonRemTurns() == 0) {
				pCardEight->free(playerNum);
				pOut->PrintMessage("You are now free from next turn!");
			}
			else {
				pOut->PrintMessage("You are locked in prison! " + to_string(pPlayer->GetPrisonRemTurns()) + " turns remaining.");
			}
			pGrid->AdvanceCurrentPlayer();
			pGrid->UpdateInterface();
		}
		else if (pPlayer->GetCardFourEffect()) {
			pPlayer->SetCardFourEffect(0);
			pOut->PrintMessage("You will be free from the next turn.");
			pGrid->AdvanceCurrentPlayer();
			pGrid->UpdateInterface();
		}
		else {
			// BIG BUG!!!
			if (pPlayer->GetTurnsOnFire()) {
				pPlayer->SetTurnsOnFire(pPlayer->GetTurnsOnFire() - 1);
				pOut->PrintMessage("You are under attack by fire, deducting 20 coins... " + to_string(pPlayer->GetTurnsOnFire()) + " turns remaining");
				pPlayer->SetWallet(pPlayer->GetWallet() - 20);
			}
			if (pPlayer->GetPoison() > 0) {
				pGrid->PrintErrorMessage("Oops You are posioned. The dicenumber will be deducted by 1");
				pPlayer->DecrementPoison();
				inputDiceValue--;
			}
			// 4- Move the currentPlayer using function Move of class player
			pPlayer->Move(pGrid, inputDiceValue);
			// 5- Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
			pGrid->UpdateInterface();
		}
	}
}

InputDiceValueAction::~InputDiceValueAction()
{

}