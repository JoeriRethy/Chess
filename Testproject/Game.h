#pragma once
#include "Pieces.h"
#include "Game.h"
#include "string"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Board.h" //seperate header files
#include <windows.h>
#include <iostream>
#include "Startselect.h"
#include "Game.h"


class Game  // usefull class 
{
public:
	Game();
	~Game();
	string getbanner(ifstream &file);

private:
	bool delay = true;
	ifstream reader;
	string printString;
	bool playerturn = true;
	bool game = true;
	const int moveCheck = 0;
	string moveInput;
	vector<Pieces*>StartBoard;
	class Board *newboard = nullptr; // dynamic memory allocation (new)
	class Startselect *newstartselect = nullptr;
protected:
	const bool win = false;
	string location;
	string newlocation;
};

