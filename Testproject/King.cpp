#include "stdafx.h"
#include  <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;
#include "King.h"

//Constructor for the King that initialises the piece type to King
King :: King() : BasePiece(){
  type = "King"; 
}


//Destructor for the King object
King :: ~King(){

}


//Checks whether the move to be made by the king is valid
//Returns true if invalid
//Else returns false
bool King :: checkValid(string start, string end, map<string, BasePiece*> &currentBoard){
  if(checkStationary(start, end))
    return true;

  if(checkHorizontal(start, end) && checkVertical(start, end) && checkDiagonal(start, end))
    return true;

  if(checkOneSquare(start, end))
    return true;

  if(checkLandingPosition(start, end, currentBoard))
    return true;

  return false;
}


