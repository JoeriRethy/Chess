#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;
#include <vector>
#include "BasePiece.h"
#include "ChessBoard.h"
#include <map>
#include <string>
#include "Constants.h"

//Constructor for the BasePiece
BasePiece :: BasePiece(){
  type = "None";
  coloured = false;
  firstMove = true;
}


//Sets the bool coloured property of the object to true (black) 
void BasePiece :: setBlack(){
  coloured = true;
}


//Returns the bool coloured property of the object
//False is white and True is black
bool BasePiece :: getColour(){
  return coloured;
}


//Returns the type property of the piece
string BasePiece :: getType(){
  return type;
}


//Returns whether the move is the firstMove
bool BasePiece :: getFirstMove(){
  return firstMove;
}


//Sets the firstMove property of the object to false
void BasePiece :: setFirstMove(){
  firstMove = false;
}


//Helper function that checks whether the piece stays stationary
//Returns true if it does
//Else returns false
bool BasePiece :: checkStationary(string start, string end){
  if(start.compare(end) == 0)
    return true;
  return false;
}


//Helper function that checks whether the move is vertical
//Returns false if it is
//Else returns true
bool BasePiece :: checkVertical(string start, string end){
  if(start[0] == end[0])
    return false;
  return true;
}


//Helper function that checks whether the move is horizontal
//Returns false if it is 
//Else returns true
bool BasePiece :: checkHorizontal(string start, string end){
  if(start[1] == end[1])
    return false;
  return true;
}


//Helper function that checks whether the move is diagonal
//Returns false if it is
//Else returns true
bool BasePiece :: checkDiagonal(string start, string end){
  string position = start;
  int firstPositionDifference = start[0] - end[0];
  int secondPositionDifference = start[1] - end[1];
  if(abs(firstPositionDifference) == abs(secondPositionDifference))
    return false;

  return true;
}


//Helper function for checkPath
//Stores the positions that the piece has to pass through to get to the final position
vector<string> BasePiece :: path(string start, string end){
  vector<string> currentPath;
  string temp = start;

  while(temp != end){
    if(start[0] < end[0]){
       temp[0]++;
    }
    else if(start[0] > end[0]){
      temp[0]--;
    }
    if(start[1] < end[1]){
      temp[1]++;
    }
    else if(start[1] > end[1]){
     temp[1]--;
    }
    currentPath.push_back(temp);
  } 

  if(currentPath.size() != 0){
    currentPath.erase(currentPath.end()-1);
  }
  
  return currentPath;
}


//Checks whether the object's path from start to end is clear
//Returns false if it is clear
//Else returns true
bool BasePiece :: checkPath(string start, string end, map<string, BasePiece*> &currentBoard){
  vector<string> pathPoint = path(start, end);

  //Only moving one space, no need to check if square is occupied
  if(pathPoint.size() == 0)
    return false;
 
  vector<string> :: iterator it;
  for(it = pathPoint.begin(); it != pathPoint.end(); it++){
    if(currentBoard.find(*it) != currentBoard.end())
      return true;
  }

  return false;
}


//Checks whether the landing position of the piece is occupied by its own team
//Returns false if it is not
//Else returns true 
bool BasePiece :: checkLandingPosition(string start, string end, map<string, BasePiece*> &currentBoard){ 
  map<string, BasePiece*> ::iterator it;
  it = currentBoard.find(end);
  if(it != currentBoard.end()){
    if(currentBoard[end]->getColour() == currentBoard[start]->getColour())
      return true;
   }
  return false;
}


//Checks whether the move is only one square
//Used by the King and Pawn child classes
bool BasePiece :: checkOneSquare(string start, string end){
  if(((abs(start[0]- end[0])) > 1) || ((abs(start[1] - end[1]))> 1))
    return true;
  return false;
}


//Returns a vector of positions that the piece at end can potentially move to
vector<string> BasePiece :: findAllMoves(string end, map<string, BasePiece*> &currentBoard){
  string position = firstSquare;
  vector<string> validMoves;

  for(position[0]=fileFirst; position[0] <= fileLast; position[0]++){
    for(position[1]=rankFirst; position[1] <= rankLast; position[1]++){
     if(currentBoard.find(position)==currentBoard.end() || 
	 (currentBoard.find(position) != currentBoard.end() &&
	  currentBoard[position]->getColour() != currentBoard[end]->getColour())){
	if(!currentBoard[end]->checkValid(end, position, currentBoard)){
	  validMoves.push_back(position);
	}
      }
    }
  }
  return validMoves;
}
