#pragma once
#include "Card.h"
class CardTwelve :
    public Card
{
public:
    CardTwelve(const CellPosition& pos);

    virtual void ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    virtual void Save(ofstream& outFile, int Type);

    virtual void Open(ifstream& inFile);

    Card* getCopy();

    virtual ~CardTwelve();
};

