#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

class Startselect 
{	
public:
	Startselect();
	~Startselect();
	class Player *game = nullptr;
	class Humanplayer *playerone = nullptr;
	class Humanplayer *playertwo = nullptr;
	bool player;
protected:
	struct info
	{
		unsigned char Name[30];
		unsigned int Age;
	}PlayerOne,PlayerTwo;
	friend class Game;
};

