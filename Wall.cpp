/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a charter skin to the pack, approach a figure, or move to another part
**      of the kingdom.
************************************************************************************/

#include "Wall.hpp"

Wall::Wall() {
    object = SKIN;
    healthChange = -15;
    name = "the Wall";
}

/************************************************************************************
 * This function gives the user 3 options: Add a charter skin to the pack, approach
 * a figure in the shadows (Dead creature), or move to another part of the kingdom.
************************************************************************************/
int Wall::menu() {
    int maxNum = 3;

    std::cout << "Lirael is at the Wall between the Old Kingdom and Ancelstierre. What should she do?\n";

    std::cout << "1. Add a charter skin to Lirael's pack\n";
    std::cout << "2. Approach a figure in the shadows\n";
    std::cout << "3. Move to another part of the kingdom\n";

    std::string choiceString;
    std::cin >> choiceString;

    int choiceInt;
    choiceInt = isInt(choiceString, 1, maxNum);

    if (choiceInt == 2) {
        std::cout << "Oh no, the shadowy figure is a Dead Hand!\n";
        //Ring bells?
    }

    return choiceInt;
}