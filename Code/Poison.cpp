#include "Poison.h"
#include "Player.h"

int Poison::playerNumToPoison;

Poison::Poison(ApplicationManager* pApp) : Attack(pApp)
{

}

void Poison::ReadActionParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int playernum = pGrid->GetCurrentPlayer()->GetPlayerNum();
	
	do {
		pOut->PrintMessage("Choose a player to poison. For 5 turns, 1 will be deducted from his dice roll");
		playerNumToPoison = pIn->GetInteger(pOut);
	} while (playerNumToPoison < 0 || playerNumToPoison > 3 || playerNumToPoison == playernum);
	pOut->PrintMessage("Player " + to_string(playerNumToPoison) + " posioned successfully!");

	
}

Poison::~Poison()
{
}

// Execute the action
void Poison::Execute(Grid* pGrid)
{
	ReadActionParameters(pGrid);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	for (int i = 0; i < MaxPlayerCount; i++) {
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum() == playerNumToPoison) {
			pGrid->GetCurrentPlayer()->Poison();
		}
	}

}
