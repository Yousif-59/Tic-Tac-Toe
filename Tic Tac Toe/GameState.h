// File Name: GameState.h
// Author: Yousif Al Saadi
// Collaborators: Landon Reese
// Date: 4/17/2022
// Assignment Number: 6
// CS 2308 Spring 2022
// The class file

#ifndef LAB6_PART1_GAMESTATE_H
#define LAB6_PART1_GAMESTATE_H
#include <iostream>
#include "MoveStack.h"


class GameState {
    char boardState[3][3];
    MoveStack moveStack;
public:
    GameState();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out);
    bool checkLastPlayerWin();
};


#endif //LAB6_PART1_GAMESTATE_H
