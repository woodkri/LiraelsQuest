/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class runs the game. It includes a pointer to the character and
**      each of the Space classes, a bool for winning the game, and a time limit
**      variable. It also includes a constructor and destructor as well as functions
**      to play the game, and print a map.
************************************************************************************/

#ifndef INC_162FINALPROJECT_GAME_HPP
#define INC_162FINALPROJECT_GAME_HPP

#include "Lirael.hpp"

class Game {
private:
    Lirael* lirael;
    Space* abhorsenHouse;
    Space* belisaere;
    Space* clayrGlacier;
    Space* death;
    Space* northernBorder;
    Space* wall;
    bool won;
    int timeLimit;
public:
    Game();
    void play();
    void print();
    ~Game();
};


#endif //INC_162FINALPROJECT_GAME_HPP
