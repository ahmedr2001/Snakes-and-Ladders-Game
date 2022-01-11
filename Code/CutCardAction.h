#pragma once

#include "Action.h"

class CutCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; //  cell position of the card

public:

	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CutCardAction parameters (cardNumber, cardPosition)

	virtual void Execute(); // Applies the effect of Cut action on the passed Player
	                                                  // by putting card in clipboard and removing it from grid
	virtual ~CutCardAction(); // Virtual Destructor
};
