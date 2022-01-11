#pragma once
#include "Card.h"
class CardEight :
    public Card
{
    static int bailMoney;
    static int arrRemDays[MaxPlayerCount];
    static bool arrJailedPlayers[MaxPlayerCount];
    static bool done;
public:
    CardEight(CellPosition& pos);

    virtual ~CardEight();

    virtual void ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    bool isJailed(int playerNum) const;

    int GetRemDays(int playerNum) const;

    void DecrementRemDays(int playerNum);

    virtual void Save(ofstream& outFile, int Type);

    virtual void Open(ifstream& inFile);

    Card* getCopy();

    void free(int playerNum);
};

