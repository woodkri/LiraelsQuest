/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      use the Dark Mirror for a message, walk through Death, or move back to the
**      last space she was in.
************************************************************************************/

#include "Death.hpp"

Death::Death() {
    healthChange = -30;
    name = "Death";
}

/************************************************************************************
 * This function gives the user 3 options: Use her mirror to get a message, walk
 * through Death, or move back to the last space she was in.
************************************************************************************/
int Death::menu() {
    int maxNum = 3;

    std::cout << "Lirael has entered Death. What should she do?\n";

    std::cout << "1. Use her Dark Mirror to get a message\n";
    std::cout << "2. Walk along the edge of Life to see if she can find any clues\n";
    std::cout << "3. Move back to her body in Life\n";

    std::string choiceString;
    std::cin >> choiceString;

    int choiceInt;
    choiceInt = isInt(choiceString, 1, maxNum);

    if (choiceInt == 2) {
        std::cout << "A dead creature appears!\n";
        //Ring bells?
    }

    return choiceInt;
}