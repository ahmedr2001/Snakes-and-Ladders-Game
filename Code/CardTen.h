#pragma once
#include "Card.h"

class CardTen : public Card
{
	//Parameters:
	static int CardPrice; //static card 10 price 
	static int Fees; //static card 10 fees 
	static Player* card10owner; //static card 10 owner
	static bool done; //static bool check if it has owner or not
public:
	CardTen(const CellPosition& pos); // A Constructor takes card position

	static void setowner(Player* p); //setter to set card 10 owner

	static void nullowner(); // removing owner 

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card 10

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual void Save(ofstream& outFile, int Type); //save card 10 data using fstream

	virtual void Open(ifstream& inFile); //load card 10 data using fstream

	Card* getCopy(); //get copy of card 10 

	virtual ~CardTen(); // A Virtual Destructor
};



