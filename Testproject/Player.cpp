#include "stdafx.h"
#include "Player.h"



Player::Player()
{
}


Player::~Player()
{

}

const int Player::getGuess()
{
	return 0;
}

void Player::play(Player &player1, Player &player2) // call by reference 
{
	int answer = 0, guess = 0;
	bool win = false;
	srand(time(NULL));
	answer = rand() % 10 + 1;

	while (!win)
	{
		
		cout  << "First player his/her turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win)
		{
			Player::playerTwoCheck = false;
			Player::playerOneCheck = true;
			return;
		}
		cout << "Second player his/her turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
		if (win)
		{
			Player::playerTwoCheck = true;
			Player::playerOneCheck = false;
			return;
		}

	}
}

bool Player::checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		cout << "" << endl;
		return true;
	}
	else if (answer < guess)
	{
		cout << "Your guess is too high." << endl;
		cout << "" << endl;
	}
	else
	{

		cout << "Your guess is too low." << endl;
		cout << "" << endl;
		return false;
	}
}