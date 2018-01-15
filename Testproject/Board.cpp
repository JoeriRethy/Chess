#include "stdafx.h"
#include "Board.h"
#include "Pieces.h"
#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;

Board::Board()
{
}

Board::~Board()
{
}

void Board::generateBoard(vector<Pieces*> allLocations) // Generate the entire board
{
	
	system("cls");
	for (int i = 1; i <= 9; i++)
		generateHorizontalLine(6, 3 * i, 32, i);
	for (int i = 0; i <= 8; i++)
		generateVerticalLine(6 + 8 * i, 3, 25, i);
	markPiece(allLocations);
}

void Board::generateHorizontalLine(int x, int y, int length, int rowNum)   // Generate Horizontal lines
{
	if (rowNum<9)
	{
		gotoXY(x - 2, y + 2);
		cout << rowNum;
	}
	gotoXY(x, y);
	for (int i = 0; i<length; i++)
		cout << "--";
	if (rowNum<9)
	{
		gotoXY(72, y + 2);
		cout << rowNum;
	}
}

void Board::generateVerticalLine(int x, int y, int length, int colNum) // Generate Vertical lines
{
	if (colNum<8)
	{
		gotoXY(x + 4, y - 1);
		cout << char(colNum + 'a');
	}
	for (int i = 0; i<length; i++)
	{
		gotoXY(x, y + i);
		cout << "|";
	}
	if (colNum<8)
	{
		gotoXY(x + 4, 28);
		cout << char(colNum + 'a');
	}
}

void Board::gotoXY(int x, int y) // function for locating coordinations a
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // this is the active console screen buffer
	COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void Board::markPiece(std::vector<Pieces*> allLocations) // Mark a piece on its location 
{
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i<32; i++)
	{
		int x = (allLocations[i]->x - 'a') * 8 + 10;
		int y = (allLocations[i]->y - 1) * 3 + 5;
		gotoXY(x, y);

		if (allLocations[i]->pieceType == "Black")
		{
			SetConsoleTextAttribute(hConsole, 11);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
		}
		if (allLocations[i]->pieceName == "Rook")
		{
			cout << "R";
		}
		else if (allLocations[i]->pieceName == "King")
		{
			cout << "K";
		}
		else if (allLocations[i]->pieceName == "Horse")
		{
			cout << "H";
		}
		else if (allLocations[i]->pieceName == "Queen")
		{
			cout << "Q";
		}
		else if (allLocations[i]->pieceName == "Pawn")
		{
			cout << "P";
		}
		else if (allLocations[i]->pieceName == "Bishop")
		{
			cout << "B";
		}
		SetConsoleTextAttribute(hConsole, 15);
	}
	gotoXY(1, 30);
}

