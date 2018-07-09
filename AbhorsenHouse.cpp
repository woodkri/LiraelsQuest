/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a bell bandolier to the pack, take a bath to regain health, move to
**      another part of the kingdom, and get a random piece of advice from a cat
**      who lives in the house.
************************************************************************************/

#include "AbhorsenHouse.hpp"
#include <iostream>
#include "isInt.hpp"

AbhorsenHouse::AbhorsenHouse() {
    object = BELLS;
    healthChange = 10;
    name = "Abhorsen's House";
}

/************************************************************************************
 * This function gives the user 4 options: add bells to the pack, rest to regain
 * some health, move to another part of the kingdom, or approach Mogget to see what
 * he says.
************************************************************************************/
int AbhorsenHouse::menu() {
    //Number of options in this menu
    int maxNum = 4;

    std::cout << "Lirael is in the Abhorsen's house. What should she do?\n";

    std::cout << "1. Add bell bandolier to Lirael's pack\n";
    std::cout << "2. Take a bath and rest for a bit\n";
    std::cout << "3. Move to another part of the kingdom\n";
    std::cout << "4. Approach the white cat who sauntered into the room\n";

    std::string choiceString;
    std::cin >> choiceString;

    int choiceInt;
    choiceInt = isInt(choiceString, 1, maxNum);

    if (choiceInt == 4) {
        mogget();
    }
    return choiceInt;
}

/************************************************************************************
 * This function outputs text from Mogget, chosen from 4 options at random.
************************************************************************************/
void AbhorsenHouse::mogget() {
    int advice = rand() % 3 + 1;

    if (advice == 1) {
        std::cout << "The cat looks up from licking its paw and says, 'Much as I dislike her, it's probably \n"
                  "a good idea for you to keep your Disreputable Dog around.'\n\n";
    }
    else if (advice == 2) {
        std::cout << "The cat tosses its head and the ring of the tiny bell around its collar makes you both \n"
                  "a little sleepy. 'I'm Mogget,' it says after a big yawn. 'Why are you interrupting my nap?'\n\n";
    }
    else if (advice == 3) {
        std::cout << "Mogget the cat leaps up onto a chair at the table in front of Lirael. 'If you want my \n"
                  "advice,' he says, 'I'd try using a Dark Mirror in Death for some clues. You are a Remembrancer \n"
                  "after all, it goes with the territory.'\n\n";
    }
    else if (advice == 4) {
        std::cout << "'Off to defeat Chlorr, are we?' purrs the cat. 'Good luck with that. I'd keep your \n"
                  "bells with you no matter what. You never know when you might need to use them.'\n\n";
    }

}