#pragma once
#include "Attack.h"
class Poison :
	public Attack
{
private:
	static int playerNumToPoison;
	// [Action Parameters]
public:
	Poison(ApplicationManager* pApp); // A Constructor

	static void ReadActionParameters(Grid* pGrid);

	static  void Execute(Grid* pGrid);

	virtual ~Poison(); // A Virtual Destructor
};

