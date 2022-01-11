#pragma once
#include "Card.h"
class CardSix :
    public Card
{
    int XdestinationCell;
    int YdestinationCell;
public:
    CardSix(const CellPosition & pos);
    void ReadCardParameters(Grid* pGrid);
    void Apply(Grid* pGrid, Player* pPlayer);
    virtual void Save(ofstream& outFile, int Type);
    virtual void Open(ifstream& inFile);
    Card* getCopy();
    ~CardSix();
};

