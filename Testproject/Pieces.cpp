#include "stdafx.h"
#include "Pieces.h"
#include "Board.h"
#include "vector"

using namespace std;

Pieces::Pieces(string pieceVirtualType, string pieceVirtualName,const unsigned char Virtualx,const int Virtualy, MoveOptions moveO, CatchOptions catchO,const int maxmoves)
{
	pieceType = pieceVirtualType;
	pieceName = pieceVirtualName;
	x = Virtualx;
	y = Virtualy;
	catchOption = catchO;
	moveOption = moveO;
	maxMoves = maxmoves;
}

Pieces::~Pieces()
{
}
