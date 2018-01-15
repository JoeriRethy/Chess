#include "stdafx.h"
#include "Startselect.h"
#include "Player.h"
#include "Humanplayer.h"


using namespace std;

Startselect::Startselect()
{

	game = new Player();
	playerone = new Humanplayer();
	playertwo = new Humanplayer();
	
	cout << "Player 1, please fill in your name:";
	cin >> PlayerOne.Name;
	cout << "Now your age:";
	cin >> PlayerOne.Age;

	cout << "Player 2, please fill in your name:";
	cin >> PlayerTwo.Name;
	cout << "Now your age:";
	cin >> PlayerTwo.Age;

	cout << " " << endl;

	cout << "Who wil start?" << " " << PlayerOne.Name << " " << "or" << " " << PlayerTwo.Name << endl;
	cout << "Guess a number between 0-10. The first who guesses it, starts !" << endl;

	cout << "" << endl;
	game->play(*playerone, *playertwo);
	
	if (game->playerOneCheck == true && game->playerTwoCheck == false)
	{
		player = true;
		cout << "" << endl;
		cout << " May the odds be in your favor " << PlayerOne.Name <<endl;
		getchar();
	}

	else if (game->playerTwoCheck == true && game->playerOneCheck == false)
	{
		player = false;
		cout << "" << endl;
		cout << "May the odds be in your favor " << PlayerTwo.Name << endl;
		getchar();
	}
	
}


Startselect::~Startselect()
{
	delete game;   
	game = nullptr;  

	delete playerone;
	playerone = nullptr;

	delete playertwo;
	playertwo = nullptr;
}






