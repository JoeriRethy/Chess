#pragma once
#include "vector"
#include "Game.h"
#include "Pieces.h"
using namespace std;
class Board //seperate header files
{
	
public:
	Board();
	~Board();
	void generateBoard(vector<Pieces*> allLocations);
	void generateHorizontalLine(int x, int y, int length, int rowNum);
	void generateVerticalLine(int x, int y, int length, int colNum);
	void gotoXY(int x, int y);
	void markPiece(std::vector<Pieces*> allLocations);
};