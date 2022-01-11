#pragma once
#include "Card.h"

class CardEleven : public Card
{
	//Parameters:
	static int CardPrice; //static card 11 price 
	static int Fees; //static card 11 fees 
	static Player* card11owner; //static card 11 owner
	static bool done; //static bool check if it has owner or not
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	static void setowner(Player* p); //setter to set card 11 owner

	static void nullowner(); // removing owner 

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card 11

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual void Save(ofstream& outFile, int Type); //save card 11 data using fstream

	virtual void Open(ifstream& inFile); //load card 11 data using fstream

	Card* getCopy(); //get copy of card 11

	virtual ~CardEleven(); // A Virtual Destructor
};



