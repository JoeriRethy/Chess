#pragma once

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "Startselect.h"

using namespace std;

class Player //base class for humanplayer

{
public:
	Player();
	~Player();
	const virtual int getGuess();  // Vitual function + Getter 
	int guess;

	void play(Player &player1, Player &player2);
	bool checkForWin(int guess, int answer);

protected:
	bool playerOneCheck;
	bool playerTwoCheck;
	friend class Startselect;
};

