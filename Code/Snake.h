#pragma once
#include "GameObject.h"
class Snake :
    public GameObject
{

	CellPosition endCellPos;
public:
    Snake(const CellPosition& startCellPos, const CellPosition& endCellPos);
	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual void Save(ofstream& outFile, int Type);
	virtual void Open(ifstream& inFile);

	virtual GameError IsOverLapping(GameObject* NewGameObject) const;

	virtual bool IsValid();

	virtual ~Snake(); // Virtual destructor
};

