#pragma once
#include "Action.h"
class DeleteGameObjectAction :
    public Action
{

    CellPosition GameObjectPosition;
public:
    DeleteGameObjectAction(ApplicationManager* pApp);
    virtual ~DeleteGameObjectAction();
    virtual void Execute();
    virtual void ReadActionParameters();
};

