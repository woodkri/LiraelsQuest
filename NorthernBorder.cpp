/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      accomplish her missing by fighting Chlorr or run away.
************************************************************************************/

#include "NorthernBorder.hpp"

NorthernBorder::NorthernBorder() {
    name = "Northern Border";
}

/************************************************************************************
 * This function gives the user 2 options: Fight Chlorr or run away.
************************************************************************************/
int NorthernBorder::menu() {
    int maxNum = 2;

    std::cout << "Lirael has reached the northern border of the Old Kingdom. There is Chlorr, \n";
    std::cout << "the necromancer who has been causing problems all throughout the kingdom!\n";
    std::cout << "What should Lirael do?\n";

    std::cout << "1. Fight Chlorr\n";
    std::cout << "2. Run away back south\n";

    std::string choiceString;
    std::cin >> choiceString;

    int choiceInt;
    choiceInt = isInt(choiceString, 1, maxNum);

    //To match health and moves in other classes
    choiceInt++;

    return choiceInt;
}