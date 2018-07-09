/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This program implements a one-player text-based game where the user
**      moves through spaces in the Old Kingdom to get items and accomplish goals.
**      The Old Kingdom is based on the book series of the same name, by Garth Nix.
************************************************************************************/

#include <iostream>
#include "Game.hpp"

int main() {
    unsigned seed = time(0);
    srand(seed);

    Game myGame;
    myGame.play();

    return 0;
}