#include "stdafx.h"
#include  <iostream>
#include <vector>
#include <map>

using namespace std;
#include "Queen.h"

//Constructor for the Queen class that initialises the type to Queen
Queen :: Queen() : BasePiece(){
  type = "Queen"; 
}


//Destructor for the Queen object
Queen :: ~Queen(){

}


//Checks that the move to be made by the Queen piece is valid
//Returns true if invalid
//Else returns false
bool Queen :: checkValid(string start, string end, map<string, BasePiece*> &currentBoard){

  if(checkStationary(start, end))
     return true;

  if(checkHorizontal(start,end) && checkVertical(start, end) && checkDiagonal(start, end))
    return true;

  if(checkPath(start, end, currentBoard))
    return true;

  if(checkLandingPosition(start, end, currentBoard))
     return true;

  return false;
}
