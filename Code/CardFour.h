#pragma once
#include "Card.h"

class CardFour : public Card
{
private:
	bool Freed = true; //bool determine if player is free or not
	static bool Card4Players[MaxPlayerCount]; // static bool array carring data if player is card 4 affected or not 
	
public:

	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	bool isCard4Players(int playerNum) const; //check if player is on card 4

	bool isfree() const; // check if the is free or not

	void free(int playerNum); //freeing the player after one dice roll

	virtual void Save(ofstream& outFile, int Type); //save card 4 data using fstream

	virtual void Open(ifstream& inFile); //load card 4 data using fstream

	Card* getCopy(); //get copy of card 4

	virtual ~CardFour(); // A Virtual Destructor
};
