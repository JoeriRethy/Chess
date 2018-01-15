#include "stdafx.h"
#include  <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;
#include "Knight.h"

//Constructor for the knight class that initialises the object to be of type knight
Knight :: Knight() : BasePiece(){
  type = "Knight";
}


//Destructor for the Knight object
Knight :: ~Knight(){

}


//Checks that the move to be made by the Knight is valid
//Returns true if the move is invalid
//Else returns false
bool Knight :: checkValid(string start, string end, map<string, BasePiece*> &currentBoard){
  if(checkStationary(start, end))
    return true;

  if(checkLShape(start, end))
    return true;
  
  if(checkLandingPosition(start, end, currentBoard))
    return true;

  return false;
}


//Helper function for checkValid that checks that the move is of the correct shape
//Returns true if invalid
//Else returns false
bool Knight :: checkLShape(string start, string end){
  if(abs(start[0]-end[0])==2){
    if(abs(start[1]-end[1])==1)
      return false;
  }
  if(abs(start[0]-end[0])==1){
    if(abs(start[1]-end[1])==2)
      return false;
  }
  return true;
}
