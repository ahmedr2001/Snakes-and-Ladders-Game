#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v < NumVerticalCells) {
		vCell = v;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < NumHorizontalCells) {
		hCell = h;
		return true;
	}

	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if (vCell < 0 || vCell >= NumVerticalCells || hCell < 0 || hCell >= NumHorizontalCells) {
		return false;
	}

	return true; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int x = cellPosition.VCell();
	int y = cellPosition.HCell();
	if (x == -1 || y == -1) {
		return -1;
	}
	int cellPos = 99 - (x * 11 + (10 - y));
	if (cellPos > 0 && cellPos < 100)
		return cellPos;// this line should be changed with your implementation
	return -1;
}


CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position(-1, -1);

	/// TODO: Implement this function as described in the .h file
	if (cellNum > 0 && cellNum < 100) {
		int vertical = 8 - ((cellNum - 1) / 11);
		int horizontal = (cellNum % 11) - 1;
		if (horizontal == -1) {
			horizontal = 10;
		}
		position.SetVCell(vertical);
		position.SetHCell(horizontal);

		// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
		//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	}
	return position;
	
}


void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file

	int currentNum = GetCellNum();
	int toBeChangedNum = currentNum + addedNum;
	if (toBeChangedNum > 99) {
		toBeChangedNum = 99;
	}
	if (toBeChangedNum < 0) {
		toBeChangedNum = 0;
	}

	*this = GetCellPositionFromNum(toBeChangedNum);


	// Note: this function updates the data members (vCell and hCell) of the calling object

}