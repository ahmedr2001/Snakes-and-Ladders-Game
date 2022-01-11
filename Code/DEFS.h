#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action	
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	///TODO: Add more action types of Design Mode
	COPY_CARD,
	CUT_CARD,
	PST_CARD,
	DEL_GM_OBJ,
	SAVE_GRID,
	OPEN_GRID,
	//  [2] Actions of Play Mode


	///TODO: Add more action types of Play Mode
	ROLL_DICE,// Roll Dice Action
	INPT_DICE_VAL,
	NEW_GAME,
	TO_DESIGN_MODE, // Go to Design Mode
	EXITT,
	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif