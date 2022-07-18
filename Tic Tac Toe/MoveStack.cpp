// File Name: GameState.cpp
// Author: Yousif Al Saadi
// Collaborators: Landon Reese
// Date: 4/17/2022
// Assignment Number: 6
// CS 2308 Spring 2022
// This file is setting up the rules and requirments for the game. 

#include <iostream>
#include "MoveStack.h"

//MoveStack(): it initalizes the stack

MoveStack::MoveStack(){ //Initializes the stack.
  size = 0;
}

//getSize(): it checks the current size of the stack.
//return: it returns the current size of the stack
int MoveStack::getSize(){ //Returns the size of the stack (number of Moves currently on the stack).
  return size;
} 

//top: insert a move on top of the stack.
//return: it retunrs a move on top of the stack. 

Move MoveStack::top(){ //Returns a move on top of the stack (but does not remove it).
  Move invalidMove;
  invalidMove.x = -1, invalidMove.y = -1;
  if(size == 0){ //if there are no moves in the stack
    std::cout << "There are no moves in the stack." << std::endl;
    return invalidMove;
  }
  
  Move ret = arr[size-1];
  return ret;
}

//push: it adds a move to the top of the stack. 
void MoveStack::push(Move move){ //Adds the move to the top of the stack.
  if(size < 9 && size >= 0){ //if stack isn't full
    arr[size] = move;
    size++;
  } 
}

//pop: checks if there's a move on top of the stacks. if so, it pops one. 
void MoveStack::pop(){
  if(size > 0){ //if there is a move in the stack
    size--;
  }
}