// File Name: GameState.cpp
// Author: Yousif Al Saadi
// Collaborators: Landon Reese
// Date: 4/17/2022
// Assignment Number: 6
// CS 2308 Spring 2022
// This file is setting up the rules and requirments for the game. 

#include "GameState.h"

// checkLastPlayer: It determines the winner in the game 
// returns: returns either true or false depending on the current player and the moves during the game. 

bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

// GameState: It initilizes out the board to all underscore character
// returns: returns either true or false depending on the current player and the moves during the game.

GameState::GameState(){
  const int SIZE = 3;
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      boardState[i][j] = '_';
    }
  }
} // Initializes the board to all underscore characters ('_').

// getCurrentPlayer: it check the next move of the player by checking even or odd to determine the next player. 
// returns: it return either true or false depending on the player. 
int GameState::getCurrentPlayer(){ //player x always goes first
  if(moveStack.getSize()%2 == 1) //if the size of the stack is odd, return true
    return true; //player 'y'
  return false;  //player 'x' or false
}// Return the player that has to make the next turn. Hint: use the size of the stack to determine who's move it is. Extra hint: odd/even.

// addMove: it checks for any incorrect moves by the players. 
// returns: it return true or false depending on the amount of trials they have left. 

int GameState::addMove(Move move){
  int min_val = 0;
  int max_val = 2;
  //std::cout <<"X="<<move.x<<" Y=" << move.y << std::endl;
  if ((move.x < min_val) || (move.x > max_val) || (move.y < min_val) || (move.y > max_val) || (boardState[move.x][move.y] != '_')) { //if the move is invalid
        return -1;
  }

   if (boardState[move.x][move.y] == '_' && moveStack.getSize() == 8){
      if(getCurrentPlayer() == 0){
        boardState[move.x][move.y] = 'x';
      } else {
        boardState[move.x][move.y] = 'o';
      }
    //# push onto stack and display board
      moveStack.push(move);
        return 0;
      }
    
  if (boardState[move.x][move.y] == '_' && moveStack.getSize() < 8) { //if space is available
    //# that space is available, update board
    if(getCurrentPlayer() == 0){
      boardState[move.x][move.y] = 'x';
    } else {
      boardState[move.x][move.y] = 'o';
    }
    //# push onto stack and display board
    moveStack.push(move); //adds move to stack
    //std::cout<<"add move"
    return 1;
  }
  
    //what the heck
    return -44;
}// Updates the state of the board and stack of the past moves given a move of the current player. If the turn is invalid (the target position is not empty) it returns -1. If all positions are filled, it returns 0. If the move was successfully done and there are moves available, it returns 1. Hint: use the size of the stack to determine if all positions are filled.

// undoLast: it check for the amount of moves and and sets up if any undo from current player.  
// returns: it return either true or false depending if the request has been successfully. 

bool GameState::undoLast(){
  int x, y;
  if(moveStack.getSize() == 0){ //there are no moves
    std::cout << "No moves to undo." << std::endl;
    return false;
  } else { //undo the move
    x = moveStack.top().x;
    y = moveStack.top().y;
    //std::cout << "Undo last." << std::endl;
    //std::cout << "Setting x to: "<< x;
    //std::cout << ":  Setting y to: "<< y << std::endl;
    boardState[x][y] = '_';
    moveStack.pop(); //calls size--
    return true;
  }
} //Undoes the last turn by changing the board state to the previous one and removing the last move from the stack. Returns true if the move was removed, false if there are no moves to undo.

// displayBoardState: it display the board to the users.
void GameState::displayBoardState(std::ostream& out){ //when you call func, displayBoardState(cout);
  int countToThree = 0;
  for(int i = 0; i < 3; i++){ //add each individual move here, in order
    for(int j = 0; j < 3; j++){
      if(countToThree == 3){
        countToThree = 0;
        out << std::endl;
      }
      out << boardState[i][j];
      countToThree++;
    }
  }
  out << std::endl;
} // Prints the board state to the "out" stream.
