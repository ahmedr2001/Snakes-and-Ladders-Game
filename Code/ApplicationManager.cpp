#include "ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "InputDiceValueAction.h"
#include "SwitchToPlayModeAction.h"
#include "SwitchToDesignModeAction.h"
#include "DeleteGameObjectAction.h"
#include "CutCardAction.h"
#include "CopyCardAction.h"
#include "PasteCardAction.h"
#include "NewGameAction.h"
#include "SaveGridAction.h"
#include "OpenGridAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;


	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:
		pAct = new SwitchToPlayModeAction(this); 
		
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new SwitchToDesignModeAction(this);
		
		break;

		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case COPY_CARD:
		pAct = new CopyCardAction(this);
		break;

	case CUT_CARD:
		// create an object of CutCardAction here
		pAct = new CutCardAction(this);
		break;

	case PST_CARD: 
		pAct = new PasteCardAction(this);
		break;

	case DEL_GM_OBJ:
		pAct = new DeleteGameObjectAction(this);
		break;

	case SAVE_GRID: 
		pAct = new SaveGridAction(this);
		break;

	case OPEN_GRID: 
		pAct = new OpenGridAction(this);
		break;

	case INPT_DICE_VAL:
		pAct = new InputDiceValueAction(this);
		break;

	case NEW_GAME:
		pAct = new NewGameAction(this);
		break;

	case EXITT:
		break;


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
