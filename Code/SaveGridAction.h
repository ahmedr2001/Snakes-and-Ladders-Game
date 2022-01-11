#pragma once
#include "Action.h"
class SaveGridAction :
    public Action
{
    string fileName;
public:
    SaveGridAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~SaveGridAction();
};

