// File Name: MoveStack.h
// Author: Yousif Al Saadi
// Collaborators: Landon Reese
// Date: 4/17/2022
// Assignment Number: 6
// CS 2308 Spring 2022
// This file is to initalize the class and struct for functions.

#ifndef LAB6_PART1_STACK_H
#define LAB6_PART1_STACK_H

struct Move{
    int x;
    int y;
    Move(){ x=0; y=0; }
    Move(int a, int b) { x=a, y=b;}
};

class MoveStack{
private:
  int size;
  int topIndex;
  Move arr[9]; 
  
public:
    MoveStack();
    //~MoveStack();
    int getSize();
    Move top();
    void push(Move move);
    void pop();
};

#endif //LAB6_PART1_STACK_H



