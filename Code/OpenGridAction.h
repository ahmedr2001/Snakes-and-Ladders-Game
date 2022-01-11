#pragma once
#include "Action.h"
class OpenGridAction :
    public Action
{
    string fileName;
public:
    OpenGridAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();

    virtual ~OpenGridAction();
};

