#include "CardTwelve.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

CardTwelve::CardTwelve(const CellPosition& pos)
	: Card(pos)
{
	cardNumber = 12;
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	ReadCardParameters(pGrid);
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	int stationNum = -1;
	int max = 0;
	for (int i = 0; i < 3; i++) {
		if (pPlayer->GetStationPrice(i) > max) {
			max = pPlayer->GetStationPrice(i);
			stationNum = i;
		}
	}
	if (stationNum != -1) {
		pPlayer->ReleaseOwnership(stationNum);
		int playerNum = -1;
		int min = INT_MAX;
		for (int i = 0; i < 4; i++) {
			pGrid->AdvanceCurrentPlayer();
			Player* currPlayer = pGrid->GetCurrentPlayer();
			if (currPlayer->GetWallet() < min) {
				min = currPlayer->GetWallet();
				playerNum = currPlayer->GetPlayerNum();
			}
		}
		pOut->PrintMessage("You will lose your most expensive station to the poorest player: Player " + to_string(playerNum));
		int diff = (playerNum - pPlayer->GetPlayerNum());
		diff = (diff >= 0) ? diff : diff + 3;
		for (int i = 0; i < diff; i++) {
			pGrid->AdvanceCurrentPlayer();
		}
		Player* currPlayer = pGrid->GetCurrentPlayer();
		switch (stationNum){
		case 0:
			CardNine::setowner(currPlayer);
			break;
		case 1:
			CardTen::setowner(currPlayer);
			break;
		case 2:
			CardEleven::setowner(currPlayer);
			break;
		}

		currPlayer->SetOwnership(stationNum, max);
		for (int i = 0; i < 4 - diff; i++) {
			pGrid->AdvanceCurrentPlayer();
		}
	}
	else {
		pOut->PrintMessage("Oops! You've got no stations.");
	}
}

CardTwelve::~CardTwelve()
{}

void CardTwelve::Save(ofstream& outFile, int Type)
{
	if (Type == 2) {
		Card::Save(outFile, Type);
		outFile << endl;
	}
}

void CardTwelve::Open(ifstream& inFile)
{
	Card::Open(inFile);
}

Card* CardTwelve::getCopy() {
	return new CardTwelve(*this);
}