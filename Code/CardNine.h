#pragma once
#include "Card.h"

class CardNine : public Card
{
	//Parameters:
	static int CardPrice; //static card 9 price 
	static int Fees; //static card 9 fees 
	static Player* card9owner; //static card 9 owner
	static bool done; //static bool check if it has owner or not
public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	static void setowner(Player* p); //setter to set card 9 owner

	static void nullowner(); // removing owner 

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card 9

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual void Save(ofstream& outFile, int Type); //save card 9 data using fstream

	virtual void Open(ifstream& inFile); //load card 9 data using fstream

	Card* getCopy(); //get copy of card 9

	virtual ~CardNine(); // A Virtual Destructor
};
