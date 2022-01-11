#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

NewGameAction::NewGameAction(ApplicationManager* pApp)
	: Action(pApp)
{

}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->SetEndGame(0);
	CellPosition start(8, 0);

	CardNine::nullowner();
	CardTen::nullowner();
	CardEleven::nullowner();

	for (int i = 0; i < 4; i++) {
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->Restart();
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->ReSetCurrentPlayerNum();
}

NewGameAction::~NewGameAction()
{

}