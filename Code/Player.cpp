#include "Player.h"
#include "Lightning.h"
#include "Ice.h"
#include "GameObject.h"
#include "Fire.h"
#include "Poison.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(1), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	Remainingattacks = 2; //set attacks remained =2
	specialattackarray[0] = false;
	specialattackarray[1] = false;
	specialattackarray[2] = false;
	specialattackarray[3] = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

int Player::GetPlayerNum() const
{
	return playerNum;
}

void Player::SetStepCount(int s)
{
	stepCount = (s >= 1 && s <= 99) ? s : 1;
}

void Player::SetTurnCount(int s)
{
	turnCount = (s >= 0 && s <= 3) ? s : 0;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet<0)
	{
		this->wallet = 0;
	}
	else
	{
		this->wallet = wallet;
	}
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetStepCount() const
{
	return stepCount;
}

int Player::GetJustRolledDiceNum() const
{
	return justRolledDiceNum;
}

void Player::SetOwnership(int stationNumber, int stationPrice)
{
	ownedStations[stationNumber] = 1;
	stationPrices[stationNumber] = stationPrice;
}

int Player::GetStationPrice(int stationNumber) const
{
	return stationPrices[stationNumber];
}

void Player::ReleaseOwnership(int stationNumber)
{
	ownedStations[stationNumber] = false;
	stationPrices[stationNumber] = 0;
}

void Player::SetPrisonRemTurns(int r)
{
	prisonRemTurns = r;
}

int Player::GetPrisonRemTurns() const
{
	return prisonRemTurns;
}

void Player::SetCardFourEffect(bool f)
{
	CardFourEffect = f;
}

bool Player::GetCardFourEffect() const
{
	return CardFourEffect;
}

void Player::SetTurnsOnFire(int f)
{
	turnsOnFire = f;
}

int Player::GetTurnsOnFire() const
{
	return turnsOnFire;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	///TODO: use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		Output* pOut = pGrid->GetOutput();
		int x, y;
		Input* pIn = pGrid->GetInput();
		turnCount++;
		if (turnCount == 3) {
			bool attackTaken = 0;
			turnCount = 0;
			if (Remainingattacks > 0){
				pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
				string checkspecialattack = pIn->GetString(pOut);
				int specialattacktype;
				if (checkspecialattack == "y")
				{
					attackTaken = 1;
					bool done = false;
					do {
						do
						{
							pOut->PrintMessage("choose the special attack 1-ice  2-fire  3-poision  4-lighting");
							specialattacktype = pIn->GetInteger(pOut);
						} while (specialattacktype < 1 || specialattacktype > 4);
						if (specialattackarray[specialattacktype - 1]) {
							pOut->PrintMessage("This attack was already used");
						}
						else done = true;
					} while (!done);
					specialattack(pGrid, specialattacktype);
				}
			}
			if (!attackTaken)
			{
				int newWallet = wallet + diceNumber * 10;
				SetWallet(newWallet);
				pOut->PrintMessage("Player " + to_string(playerNum) + " recharging " + to_string(
					diceNumber * 10) + " coins");
				pIn->GetPointClicked(x, y);
				return;
			}
		}
		else {
			justRolledDiceNum = diceNumber;
			CellPosition NewCellPos = pCell->GetCellPosition();
			int newCell = NewCellPos.GetCellNum() + justRolledDiceNum;

			NewCellPos.AddCellNum(justRolledDiceNum);
			if (newCell < 100) {
				pGrid->UpdatePlayerCell(this, NewCellPos);
				pOut->PrintMessage("Player " + to_string(playerNum) + " moving to cell number: " + to_string(NewCellPos.GetCellNum()));
				pIn->GetPointClicked(x, y);
				GameObject* pGameObject = pCell->GetGameObject();
				if (pGameObject != NULL) {
					pGameObject->Apply(pGrid, this);
				}
				stepCount = pCell->GetCellPosition().GetCellNum();
			}
			if (newCell == 100) {
				pGrid->PrintErrorMessage("Congratulations! Player " + to_string(playerNum) + " won! Click to end the game");
				pGrid->SetEndGame(true);
			}
		}
}

int Player::GetPoison() {
	return poisons;
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(stepCount) + ")";
}

void Player::specialattack(Grid* pGrid, int attacknum)
{
	switch (attacknum)
	{
	case 1:
			Ice::Execute(pGrid);
			specialattackarray[0] = true;
			Remainingattacks--;
		break;
	case 2:
			Fire::Execute(pGrid);
			specialattackarray[1] = true;
			Remainingattacks--;
		break;
	case 3:
			Poison::Execute(pGrid);
			specialattackarray[2] = true;
			Remainingattacks--;
		break;
	case 4:
			Lightning::Execute(pGrid);
			specialattackarray[3] = true;
			Remainingattacks--;
		break;
	default:
		break;
	}
}

void Player::Poison() {
	poisons=5;
}

void Player::DecrementPoison() {
	poisons--;
}
void Player::Restart()
{
	SetWallet(100);
	SetStepCount(1);
	SetTurnCount(0);
	ReleaseOwnership(0);
	ReleaseOwnership(1);
	ReleaseOwnership(2);
	prisonRemTurns = 0;
	CardFourEffect = 0;
	Remainingattacks = 2;
	specialattackarray[0] = false;
	specialattackarray[1] = false;
	specialattackarray[2] = false;
	specialattackarray[3] = false;
	turnsOnFire = 0;
	poisons = 0;

}