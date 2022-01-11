#pragma once
#include "Card.h"
class CardFive : public Card
{
public:
	CardFive::CardFive(const CellPosition& pos);
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& outFile, int Type);
	virtual void Open(ifstream& inFile);
	Card* getCopy();
	virtual ~CardFive();
};

