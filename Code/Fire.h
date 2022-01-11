#pragma once
#include "Attack.h"
class Fire :
    public Attack
{
    static int playerNumToFire;
public:
    Fire(ApplicationManager* pApp);

    static void ReadActionParameters(Grid* pGrid);

    static void Execute(Grid* pGrid);

    virtual ~Fire();
};

