#include "stdafx.h"
#include  <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;
#include "Pawn.h"
#include "ChessBoard.h"

//Constructor for the pawn class the intialises the type to Pawn
Pawn :: Pawn() : BasePiece(){
  type = "Pawn"; 

}


//Destructor for the Pawn object
Pawn :: ~Pawn(){
}


//Checks that the move to be made by the pawn piece is valid
//Returns true if it is invalid
//Else returns false
bool Pawn :: checkValid(string start, string end, map<string, BasePiece*> &currentBoard){
  bool error;
  if(checkStationary(start, end))
     return true;

  map<string,BasePiece*> :: iterator it;
  it = currentBoard.find(end);
  if(it != currentBoard.end()){
    if(currentBoard[end]->getColour() != currentBoard[start]->getColour())
      error = checkValidWhileTaking(start, end);
  }
  else 
    error = checkValidWithoutTaking(start, end, currentBoard);

  return error;
}


//Helper function for checkValid
//Checks validity of move when the Pawn will be landing on a space not occupied by the opposite team
//Returns true if invalid
//Else returns false
bool Pawn :: checkValidWithoutTaking(string start, string end, map<string, BasePiece*> &currentBoard){

  if(checkVerticalForward(start, end, currentBoard))
     return true;

   if(currentBoard[start]->getFirstMove() == 0){
     if(checkOneSquare(start, end))
       return true;
   }
   else if(currentBoard[start]->getFirstMove() == 1){
     if(checkTwoSquare(start, end) && checkOneSquare(start, end))
       return true;
     
     if(checkPath(start, end, currentBoard))
       return true;
   }

  return false;
}


//Helper function for checkValidWithoutTaking
//Checks whether the move is vertically forward
//Returns true if invalid
//Else returns false
bool Pawn :: checkVerticalForward(string start, string end, map<string, BasePiece*> &currentBoard){
  if(currentBoard[start]->getColour() == 0){
    if(start[0] == end[0] && start[1] < end[1])
      return false;
  }
  else{
    if(start[0] == end[0] && start[1] > end[1])
      return false;
  }
  return true;
}


//Helper function for checkValid
//Checks validity of move when the Pawn will be landing on a space occupied by the opposite team
//Returns true if invalid
//Else returns false
bool Pawn :: checkValidWhileTaking(string start, string end){
  if(checkDiagonal(start, end))
    return true;
  
  if(checkOneSquareDiagonal(start, end))
    return true;

  return false;
}


//Helper function for checkValidWithoutTaking
//Checks that the move is two spaces forward
//Returns true if invalid
//Else returns false
bool Pawn :: checkTwoSquare(string start, string end){
  if((abs(start[1] - end[1])) > 2)
    return true;
  return false;
}


//Helper function for checkValidWhileTaking
//Checks that the move is one space diagonal
//Returns true if invalid
//Else returns false
bool Pawn :: checkOneSquareDiagonal(string start, string end){
  if((abs(start[0]-end[0])==1 && (abs(start[1]-end[1])==1)))
     return false;
  return true;
}
