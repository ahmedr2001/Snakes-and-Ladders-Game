#pragma once
#include "Action.h"
class CopyCardAction :
    public Action
{
	// [Action Parameters]
	CellPosition cardPosition; //  cell position of the card

public:

	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CutCardAction parameters (cardNumber, cardPosition)

	virtual void Execute(); // Applies the effect of Copy action on the passed Player
	                                                  // by putting card in clipboard and not removing it from grid

	virtual ~CopyCardAction(); // Virtual Destructor
};
