// File Name: main.cpp
// Author: Yousif Al Saadi
// Date: 4/17/2022
// Assignment Number: 6
// CS 2308 Spring 2022
// This file is setting up the some of the rules and printing out some functions. 


#include <iostream>
#include "MoveStack.h"
#include "GameState.h"
using namespace std;

int main() {
  //Contains the main game loop. Players should be able to enter their move in a format "move x y", where x and y are the coordinates of the target cell. Also, players should be able to undo the previous move (of their opponent) by entering "undo". The player board should be displayed at the beginning of the game and after every valid move. After every valid move the win condition has to be checked for the last player who made the move (checkLastPlayerWin). If the win condition is reached a winner should be declared and the program should be terminated. The same goes for if the game ends in a draw.

  //START BELOW THIS LINE

  GameState game = GameState();
  string input;
  bool test1;
  int  test2 = -99;
  int x, y;
  Move move;


  game.displayBoardState(cout);
  
  do{
    cout << "Player " << game.getCurrentPlayer() << " make a turn." << endl;
      //cout << "Size: " << game.moveStack.getSize() << endl;

    cin >> input;
    
    if(input == "undo"){
      test1 = game.undoLast();

      if(test1 == true){ //only prints if there is a move to undo
        game.displayBoardState(cout);
      }
    }
    
      
    else if(input == "move"){
      cin >> x; //move.x = x;
      if(cin.fail()){
        x = -1;
      }
      cin >> y; //move.y = y;
      if(cin.fail()){
        y = -1;
      }
      move.x = x;
      move.y = y;
      
      test2 = game.addMove(move);
      
      if(test2 == -1){ //invalid move
        cout << "Incorrect move. Please try again." << endl;
      }
      if(test2 == 0){ //full game board
        if(game.checkLastPlayerWin() == 1){ //if the player wins
          game.displayBoardState(cout);
          cout << "Player " << !game.getCurrentPlayer() << " won!" << endl;
        } else { //if it's a draw
          game.displayBoardState(std::cout);
          cout << "It's a draw!" << endl;
        }
        exit(0);
      }
      
      if(test2 == 1){ //added the move successfully
        game.displayBoardState(cout);
        
      }
      
    } else {
      //test2 = -1;
      cout << "Bad Input : expected move or undo not " << input<< endl;
    }
    
  }while(!game.checkLastPlayerWin());
  cout << "Player " << !game.getCurrentPlayer() << " won!" << endl;
  return 0;
  
}