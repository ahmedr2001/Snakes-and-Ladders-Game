#include "Ice.h"
#include "Player.h"

int Ice::playernumtoice;

Ice::Ice(ApplicationManager* pApp) : Attack(pApp)
{

}

void Ice::ReadActionParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* player = pGrid->GetCurrentPlayer();
	int playernum = player->GetPlayerNum();
	do {
		pOut->PrintMessage("Choose a player to prevent from rolling the next turn");
		playernumtoice = pIn->GetInteger(pOut);
	} while (playernumtoice < 0 || playernumtoice > 3 || playernumtoice == playernum);
}

Ice::~Ice()
{
}

// Execute the action
void Ice::Execute(Grid* pGrid)
{
	ReadActionParameters(pGrid);
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum()==playernumtoice)
		{
			pGrid->GetCurrentPlayer()->SetCardFourEffect(true);
		}
	}
}
