#include "Fire.h"
#include "Player.h"

int Fire::playerNumToFire;

Fire::Fire(ApplicationManager* pApp)
	:Attack(pApp)
{

}

Fire::~Fire()
{

}

void Fire::ReadActionParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	Player* pPlayer = pGrid->GetCurrentPlayer();
	int playerNum = pPlayer->GetPlayerNum();
	do {
		pOut->PrintMessage("Choose a player to deduct 20 coins from for the next 3 turns (60 total)");
		playerNumToFire = pIn->GetInteger(pOut);
	} while (playerNumToFire < 0 || playerNumToFire > 3 || playerNumToFire == playerNum);

}

void Fire::Execute(Grid* pGrid)
{
	ReadActionParameters(pGrid);
	for (int i = 0; i < MaxPlayerCount; i++) {
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum() == playerNumToFire) {
			pGrid->GetCurrentPlayer()->SetTurnsOnFire(3);
		}
	}
}