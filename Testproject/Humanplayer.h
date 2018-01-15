#pragma once
#include "Player.h"


class Humanplayer :
	public Player  //base class
{
public:
	Humanplayer() : Player() {};
	~Humanplayer();

	const int getGuess();
};

