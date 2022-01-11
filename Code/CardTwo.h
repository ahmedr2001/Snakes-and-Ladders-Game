#pragma once
#include "Card.h"
class CardTwo :
    public Card
{

public:

    CardTwo(const CellPosition& pos); // A Constructor takes card position

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player

    virtual void Save(ofstream& outFile, int Type);

    virtual void Open(ifstream& inFile);

    Card* getCopy();

    virtual ~CardTwo(); //A virtual Destructor
};

