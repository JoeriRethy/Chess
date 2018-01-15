#pragma once
#include "string"
using namespace std;
class Pieces
{

public:
	enum CatchOptions
	{
		Schuin,
		Straight,
		allaround,
		weirdhorsecatch

	};
	enum MoveOptions
	{
		HorizontalAndVertical,
		VerticalCantMoveBack,
		Vertical,
		Horse,
		Schuin2,
		alldirections,
		weirdhorsemove
	};



	Pieces(string pieceVirtualType, string pieceVirtualName,const unsigned char Virtualx,const int Virtualy, MoveOptions moveO, CatchOptions catchO,const int maxmoves);
	~Pieces();

	string pieceType;
	string pieceName;
	
	unsigned char initialx;
	int initialy;

	unsigned char finalex;
	int finaley;
	
	char x;
	 int y;

	 MoveOptions moveOption;
	 CatchOptions catchOption;

	int maxMoves;

};