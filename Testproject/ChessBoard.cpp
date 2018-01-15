#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;
#include <vector>
#include <string>

#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Constants.h"


//Constructor for ChessBoard that initialises all the pieces at their correct starting positions
ChessBoard :: ChessBoard(){
  createBoard();
}

//Destructor for the ChessBoard object
ChessBoard :: ~ChessBoard(){
  clearBoard();
}


//Moves the piece at the position "start" to the new position "end" if the move is valid
//Calls the functions that checks for checkmate and stalemate
void ChessBoard :: submitMove(const char* startP, const char* endP){
  string start(startP), end(endP);
  
  //Checks whether the positions are valid
  if(checkMove(start, end))
    return;

  //Checks whether the move is valid
  if(currentBoard[start]->checkValid(start, end, currentBoard)){
    cout << (turnCount%2 ? "Black's " : "White's ");
    cout << currentBoard[start]->getType();
    cout << " cannot move to " << end << "!" << endl;
    return;
  }

  //Makes move if the move doesnt cause its own team to be in check
  if(makeMove(start, end))
    return;

  //Checks whether it causes the other team to be in check or checkmate
  string enemyKingPosition = (!teamInPlay ? blackKingPosition : whiteKingPosition); 
  if(checkAttackable(enemyKingPosition, !teamInPlay)){
    if(checkCheckMate(end, enemyKingPosition)){
      cout << (teamInPlay ? "White " : "Black ") << "is in checkmate " << endl;
      return;
    }
    else
      cout << (teamInPlay ? "White " : "Black ") << "is in check " << endl; 
  }

  //Increment the turncount to indicate a change in team in play
  turnCount++;
  teamInPlay = turnCount%2;

  //Checks whether the other team is now in a stalemate
  if(checkStaleMate()){
    cout << "The play is in stalemate!" << endl;
  }
}


//Clears the currentBoard of its information and restarts it with all pieces at their starting positions  
void ChessBoard :: resetBoard(){
  clearBoard();
  createBoard();
}


//Helper function for resetBoard
//Creates a new ChessBoard where all pieces are at their correct starting positions
void ChessBoard :: createBoard(){
  turnCount = 0;
  teamInPlay = 0;
  whiteKingPosition = "E1";
  blackKingPosition = "E8";
  string position;

  //Generating the white pieces
  currentBoard["A1"] = new Rook;
  currentBoard["B1"] = new Knight;
  currentBoard["C1"] = new Bishop;
  currentBoard["D1"] = new Queen;
  currentBoard["E1"] = new King;
  currentBoard["F1"] = new Bishop;
  currentBoard["G1"] = new Knight;
  currentBoard["H1"] = new Rook;
  for(position = "A2"; position[0] <= fileLast; position[0]++){
    currentBoard[position] = new Pawn;
  }

  //Generating the black pieces
  currentBoard["A8"] = new Rook;
  currentBoard["B8"] = new Knight;
  currentBoard["C8"] = new Bishop;
  currentBoard["D8"] = new Queen;
  currentBoard["E8"] = new King;
  currentBoard["F8"] = new Bishop;
  currentBoard["G8"] = new Knight;
  currentBoard["H8"] = new Rook;
  for(position = "A7"; position[0] <= fileLast; position[0]++){
    currentBoard[position] = new Pawn;
  }

  for(position[0] = fileFirst; position[0] <= fileLast; position[0]++){
    for(position[1]= '7'; position[1] <= '8'; position[1]++){
      currentBoard[position]->setBlack();
    }
  }
  
  cout << "A new chess game is started!"<<endl;
}


//Helper function for resetBoard
//Deallocates the memory pointed to by all pieces
void ChessBoard :: clearBoard(){
  map<string, BasePiece*> :: iterator it;
  for(it = currentBoard.begin(); it != currentBoard.end(); it++)
    delete it->second;
  currentBoard.clear();
}


//Calls helper functions that checks that the move is valid
//Returns true if the move is invalid
//Else returns false
bool ChessBoard :: checkMove(string start, string end){
  if(checkFormat(start))
    return true;

  if(checkFormat(end))
    return true;

  if(checkOccupied(start)){
    cout << "There is no piece at position " << start << "!" <<endl;
    return true;
  }

  if(checkDifferentTeam(start)){
    cout << "It is not " << (teamInPlay ? " White's " : "Black's ") << "turn to move!" << endl;
    return true;
  }

  return false;
}


//Helper function for checkMove
//Checks whether the position specified is in the correct format
//Returns true if invalid
//Else returns false
bool ChessBoard :: checkFormat(string position){

  //Checks that there are exactly two characters in the string position
  if(position.size() == 0) {
    cout << "No position was specified" <<endl;
    return true;
  }
  if(position.size() == 1){
    cout << "There should be two characters in the position specified." << position << endl;
    return true;
  }
  if(position.size() > 2) {
    cout << "The format for the position is wrong. There are too many characters." << position << endl;
    return true;
  }

  //Checks that the string consist of one upper alphabet and one digit
  if(!isalpha(position[0]) || position[0] < 65 || position[0] > 90) {
    cout << "The first character in the coordinates is not an upper case alphabet" << position << endl;
    return true;
  }
  if(!isdigit(position[1])){
    cout << "The second character in the position is not a digit." << position << endl;
    return true;
  }

  //Checks that the move is within the boundaries of the chessboard
  if(position[0] > fileLast){
    cout << "The position is outside the file of the board" << endl;
    return true;
  }
  if(position[1] > rankLast){
    cout << "The position is outside the rank of the board" <<endl;
    return true;
  }

  return false;
}


//Helper function for checkMove that checks whether the square is occupied
//Returns true if it is not 
//Else returns false
bool ChessBoard :: checkOccupied(string position){
  if(currentBoard.find(position) == currentBoard.end())
    return true;
  return false; 
} 


//Helper function for checkMove that checks that the chesspiece is moved by the correct team 
//Returns true if it is not
//Else returns false
bool ChessBoard :: checkDifferentTeam(string position){
  if(currentBoard[position]->getColour() != turnCount%2)
     return true;
return false;
}


//Makes move if this does not cause your team to be in check
//Returns true if move is not possible
//Else returns false
bool ChessBoard :: makeMove(string start, string end){

  //Moves the chess piece into the purported position
  map<string, BasePiece*> :: iterator it;
  it = currentBoard.find(start);
  BasePiece* tempStart = it->second;
  currentBoard.erase(start);
  it = currentBoard.find(end);
  BasePiece* tempEnd = it->second;
  currentBoard[end] = tempStart;

  //If the piece being moved is the king, updates its position
  if(!((currentBoard[end]->getType()).compare("King"))) 
    teamInPlay? (blackKingPosition = end) : (whiteKingPosition = end);
  string currentKingPosition = (teamInPlay ? blackKingPosition : whiteKingPosition);
  
  //Checks whether this causes the own team to be checked. If yes, reverse move and returns true
  if(checkAttackable(currentKingPosition, teamInPlay)){
    currentBoard[start]= tempStart;

    if(it != currentBoard.end())
      currentBoard[end] = tempEnd;
    else
      currentBoard.erase(end);

    cout << (teamInPlay ? "Black's " : "White's ");
    cout << currentBoard[start]->getType();
    cout << " cannot move to " << end << "!" << endl;

    if(!((currentBoard[start]->getType()).compare("King")))
      teamInPlay? (blackKingPosition = start): (whiteKingPosition = start);

    return true;
  }

  currentBoard[end]->setFirstMove();

  //Prints the move to the screen
  cout << (teamInPlay ? "Black's " : "White's ") << currentBoard[end]->getType();
  cout << " moves from " << start << " to " << end << " ";

  //Checks whether a piece was taken and prints to screen if one was
  if(it != currentBoard.end())
    cout << "taking " << (teamInPlay ? "White's " : "Black's ") << tempEnd->getType();

  cout << endl;
  return false;
}


//Checks whether the move causes the team to be checkmated
//Returns true if it does
//Else returns false
bool ChessBoard :: checkCheckMate(string attacker, string enemyKingPosition){
  if(checkNoHelper(attacker) && checkNoEscape(enemyKingPosition) && checkNoBlocker(attacker, enemyKingPosition))
    return true;
  return false;
}


//Checks whether the piece at positionAttacked can be attacked by the opposite team 
//Returns true if it does                           
//Else returns false    
bool ChessBoard :: checkAttackable(string positionAttacked, bool positionAttackedColour){
  string position = firstSquare;

  for(position[0] = fileFirst; position[0] <= fileLast; position[0]++){  
    for(position[1]= rankFirst; position[1] <= rankLast; position[1]++){
      if(!checkOccupied(position)){
	if( (currentBoard[position]->getColour() != positionAttackedColour) &&
	 !currentBoard[position]->checkValid(position, positionAttacked, currentBoard))
	  return true;	
      }
    }
  }
  return false;
}


//Helper function for checkCheckMate
//Checks whether there is an escape path for the king
//Returns true if there is none
//Else returns false
bool ChessBoard :: checkNoEscape(string enemyKingPosition){
  vector<string> kingAvailableMoves = currentBoard[enemyKingPosition]->findAllMoves(enemyKingPosition, currentBoard);
  vector<string> movesBlocked;

  map<string, BasePiece*> :: iterator it;
  it = currentBoard.find(enemyKingPosition);
  BasePiece* tempStart = it->second;
  currentBoard.erase(enemyKingPosition);
  
  for(unsigned int i = 0; i < kingAvailableMoves.size(); i++){
    it = currentBoard.find(kingAvailableMoves[i]);
    BasePiece* tempEnd = it->second;
    currentBoard[kingAvailableMoves[i]] = tempStart;

    if(checkAttackable(kingAvailableMoves[i], !teamInPlay))
      movesBlocked.push_back(kingAvailableMoves[i]);

    currentBoard[enemyKingPosition]= tempStart;

    if(it != currentBoard.end())
      currentBoard[kingAvailableMoves[i]] = tempEnd;
    else
      currentBoard.erase(kingAvailableMoves[i]);
  }
  
  if(movesBlocked.size() == kingAvailableMoves.size())
    return true;

  return false;
}


//Helper function for checkCheckMate
//Checks whether any of the king's teammates can remove the threat
//Returns true if there is none
//Else returns false
bool ChessBoard :: checkNoHelper(string attacker){
  if(checkAttackable(attacker, teamInPlay))
    return false;
  return true;
}


//Helper function for checkCheckMate
//Checks whether any of the King's teammate can block the threat
//Returns true if there is none
//Else returns true
bool ChessBoard :: checkNoBlocker(string attacker, string kingPosition){
  vector<string> path = currentBoard[kingPosition]->path(attacker, kingPosition);
  string position = firstSquare;

  
  for(unsigned int i =0; i< path.size(); i++){
    for(position[0] = fileFirst; position[0] <= fileLast; position[0]++){
      for(position[1]= rankFirst; position[1] <= rankLast; position[1]++){
	if(!checkOccupied(position) &&
	   (currentBoard[position]->getColour() != teamInPlay) &&
	   !currentBoard[position]->checkValid(position, path[i], currentBoard) &&
	   kingPosition!=position){
	  return false;
	}
      }
    }
  }
  return true;
}


//Checks whether there is a stalemate
//Returns true if there is
//Else returns false
bool ChessBoard :: checkStaleMate(){

  string position = firstSquare;
  vector<string> movesPossible;
  string kingPosition = (teamInPlay ? blackKingPosition : whiteKingPosition);

  for(position[0]= fileFirst; position[0] <= fileLast; position[0]++){
    for(position[1]= rankFirst; position[1]<=rankLast; position[1]++){
      movesPossible.clear();

      //Position represents the team that is trying to find a move to stop checkmate
      if(currentBoard.find(position) != currentBoard.end()&&
	 (currentBoard[position]->getColour() == teamInPlay)){

	movesPossible = currentBoard[position]->findAllMoves(position, currentBoard);
	if(movesPossible.size()!= 0){
      	  for(unsigned int i = 0; i < movesPossible.size(); i++){
	    if(!checkStaleMateHelper(position, movesPossible[i], teamInPlay)){
	      movesPossible.clear();
	      return false;
	    }
	  }
	  movesPossible.clear();
	}
      }
    }
  }
 return true;
}


//Helper function for check stalemate
//Checks whether the purported move causes the king to be checked
//Returns true if it does
//Else returns false
bool ChessBoard :: checkStaleMateHelper(string start, string end, bool teamChecked){

  //Moves the chess piece into the purported position
  map<string, BasePiece*> :: iterator it;
  it = currentBoard.find(start);
  BasePiece* tempStart = it->second;
  currentBoard.erase(start);
  it = currentBoard.find(end);
  BasePiece* tempEnd = it->second;
  currentBoard[end] = tempStart;

  //If the piece being moved is the king, updates its position
  if(!((currentBoard[end]->getType()).compare("King"))) 
    teamChecked? (blackKingPosition = end) : (whiteKingPosition = end);
  string currentKingPosition = (teamChecked ? blackKingPosition : whiteKingPosition);
  
  //Checks whether this causes the own team to be checked. If yes, reverse move and returns true
  bool attackable = checkAttackable(currentKingPosition, teamChecked);

  currentBoard[start]= tempStart;

  if(it != currentBoard.end())
    currentBoard[end] = tempEnd;
  else
    currentBoard.erase(end);

  if(!((currentBoard[start]->getType()).compare("King")))
    teamChecked? (blackKingPosition = start): (whiteKingPosition = start);

  if(attackable)
    return true;

  return false;
}








