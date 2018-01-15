#pragma once
#include "stdafx.h"
#include "Humanplayer.h"


Humanplayer::~Humanplayer()
{
}

const int Humanplayer::getGuess() //inheritance
{
	cout << "Please enter your guess: ";
	cin >> guess;
	return guess;	
}