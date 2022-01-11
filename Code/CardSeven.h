#pragma once
#include "Card.h"
class CardSeven :
    public Card
{
public:
    CardSeven(const CellPosition& pos);
    
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    
    virtual void Save(ofstream& outFile, int Type);

    virtual void Open(ifstream& inFile);

    Card* getCopy();

    virtual ~CardSeven();
};

