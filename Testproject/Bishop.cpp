#include "stdafx.h"
#include  <iostream>
#include <vector>
#include <map>

using namespace std;
#include "Bishop.h"

//Constructor for Bishop that initialises its type to Bishop
Bishop :: Bishop() : BasePiece(){
  type = "Bishop"; 
}


//Deconstructor for Bishop
Bishop :: ~Bishop(){

}


//Checks that the move to be made by the Bishop is valid
//Returns true if invalid
//Else returns false
bool Bishop :: checkValid(string start, string end, map<string, BasePiece*> &currentBoard){

  if(checkStationary(start, end))
    return true;

  if(checkDiagonal(start, end))
     return true;  

  if(checkPath(start, end, currentBoard))
    return true;

  if(checkLandingPosition(start, end, currentBoard))
    return true;

  return false;
}
