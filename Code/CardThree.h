#pragma once

#include "Card.h"
#include "RollDiceAction.h"

class CardThree : public Card
{
	
public:
	CardThree(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  
	virtual void Save(ofstream& outFile, int Type); //save card 3 data using fstream

	virtual void Open(ifstream& inFile); //load card 3 data using fstream

	Card* getCopy(); //get copy of card 3

	virtual ~CardThree(); // A Virtual Destructor
};

