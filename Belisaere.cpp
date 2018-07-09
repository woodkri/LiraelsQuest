/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a sword to the pack, obtain a golden hand (increased health capacity),
**      and move to another part of the kingdom.
************************************************************************************/

#include "Belisaere.hpp"

Belisaere::Belisaere() {
    object = SWORD;
    healthChange = 50;
    name = "Belisaere";
}

/************************************************************************************
 * This function gives the user 3 options: add a sword to the pack, ask the prince
 * for a golden hand which increases her health capacity, or move to another part of
 * the kingdom.
************************************************************************************/
int Belisaere::menu() {
    //Number of options in this menu
    int maxNum = 3;

    std::cout << "Lirael is in Belisaere. What should she do?\n";

    std::cout << "1. Add a sword to Lirael's pack\n";
    std::cout << "2. Ask Prince Sameth to make Lirael a golden hand\n";
    std::cout << "3. Move to another part of the kingdom\n";

    std::string choiceString;
    std::cin >> choiceString;

    int choiceInt;
    choiceInt = isInt(choiceString, 1, maxNum);

    return choiceInt;
}