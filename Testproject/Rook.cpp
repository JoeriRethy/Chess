#include "stdafx.h"
#include  <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;
#include "Rook.h"

//Constructor for Rook that initialises its type to Rook
Rook :: Rook() : BasePiece(){
  type = "Rook";
}


//Deconstructor for Rook
Rook :: ~Rook(){

}


//Checks that the move is valid
//Returns true if it is not 
//Else returns false
bool Rook :: checkValid(string start, string end, map<string, BasePiece*> &currentBoard){
  if(checkStationary(start, end))
    return true;
  
  if(checkHorizontal(start, end) && checkVertical(start, end))
    return true;
  
  if(checkPath(start, end, currentBoard))
    return true;

  if(checkLandingPosition(start, end, currentBoard))
    return true;

  return false;
}


//Helper function for check valid that checks whether the move by the rook is in an L shape
//Returns true if it is not
//Else returns false
bool Rook :: checkLShape(string start, string end){
  if(abs(start[0]-end[0])==2){
    if(abs(start[1]-end[1])!=1)
      return true;																																																																																											
  }
  if(abs(start[0]-end[0])==1){
    if(abs(start[1]-end[1])!=2)
      return true;
  }
  return false;
}
