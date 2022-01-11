#pragma once
#include "Action.h"
class Attack :
    public Action
{
private:
	// [Action Parameters]
	// Note: These parameters should be read in ReadActionParameters()
public:
	Attack(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute(Grid* pGrid, Player* pPlayer);

	virtual ~Attack(); // A Virtual Destructor
};
