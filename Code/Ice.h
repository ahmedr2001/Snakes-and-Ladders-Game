#pragma once
#include "Attack.h"
class Ice :
    public Attack
{
private:
	static int playernumtoice;
	// [Action Parameters]
public:
	Ice(ApplicationManager* pApp); // A Constructor

	static void ReadActionParameters(Grid* pGrid);

	static void Execute(Grid* pGrid);

	virtual ~Ice(); // A Virtual Destructor
};

