#include "CardEight.h"

bool CardEight::arrJailedPlayers[MaxPlayerCount];
int CardEight::arrRemDays[MaxPlayerCount];
int CardEight::bailMoney;
bool CardEight::done = false;

CardEight::CardEight(CellPosition& pos)
	:Card(pos)
{
	cardNumber = 8;
}

CardEight::~CardEight()
{

}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (!done){
		pOut->PrintMessage("New Card Eight: Enter money required to exit prison: ");
		bailMoney = pIn->GetInteger(pOut);
		done = 1;
	}
	else {}

	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int s;
	do {
		pOut->PrintMessage("This is a prison. Will you pay? 1-Yes 2-No");
		s = pIn->GetInteger(pOut);
	} while (s != 1 && s != 2);
	if (s == 1) {
		if (pPlayer->GetWallet() >= bailMoney)
			pPlayer->SetWallet(pPlayer->GetWallet() - bailMoney);
		else {
			pOut->PrintMessage("You don't have enough coins, you will be jailed for 3 turns.");
			int playerNum = pPlayer->GetPlayerNum();
			pPlayer->SetPrisonRemTurns(3);
			arrJailedPlayers[playerNum] = true;
			arrRemDays[playerNum] = 3;
		}
	}
	else if (s == 2) {
		pOut->PrintMessage("You will be jailed for 3 turns.");
		int playerNum = pPlayer->GetPlayerNum();
		pPlayer->SetPrisonRemTurns(3);
		arrJailedPlayers[playerNum] = true;
		arrRemDays[playerNum] = 3;
	}
}

bool CardEight::isJailed(int playerNum) const
{
	return arrJailedPlayers[playerNum];
}

int CardEight::GetRemDays(int playerNum) const
{
	return arrRemDays[playerNum];
}

void CardEight::DecrementRemDays(int playerNum)
{
	arrRemDays[playerNum]--;
}

void CardEight::free(int playerNum)
{
	arrJailedPlayers[playerNum] = false;
}

void CardEight::Save(ofstream& outFile, int Type)
{
	if (Type == 2) {
		Card::Save(outFile, Type);
		outFile << " " << bailMoney << endl;
	}
}

void CardEight::Open(ifstream& inFile)
{
	Card::Open(inFile);
	inFile >> bailMoney;
}

Card* CardEight::getCopy() {
	return new CardEight(*this);
}