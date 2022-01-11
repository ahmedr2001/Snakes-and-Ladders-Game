#pragma once
#include "Attack.h"
class Lightning :
    public Attack
{
private:
	// [Action Parameters]
public:
	Lightning(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	static void Execute(Grid* pGrid);

	virtual ~Lightning(); // A Virtual Destructor
};
