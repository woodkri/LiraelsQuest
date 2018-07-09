/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a randomized item to the pack, obtain healing, move to another part of
**      the kingdom, or speak with the Voice of the Watch for a hint.
************************************************************************************/

#include "ClayrGlacier.hpp"

ClayrGlacier::ClayrGlacier() {
    healthChange = 20;
    name = "Clayr's Glacier";
}

/************************************************************************************
 * This function gives the user 4 options: add a randomized item to Lirael's pack,
 * obtain healing from a Charter Mage, move to another part of the kingdom, or speak
 * with the Voice of the Watch for a hint.
************************************************************************************/
int ClayrGlacier::menu() {
//Number of options in this menu
    int maxNum = 4;

    std::cout << "Lirael is in the Clayr's glacier. What should she do?\n";

    std::cout << "1. Add an item to Lirael's pack\n";
    std::cout << "2. Approach a Charter Mage for healing\n";
    std::cout << "3. Move to another part of the kingdom\n";
    std::cout << "4. Speak with the Voice of the Nine Day Watch\n";

    std::string choiceString;
    std::cin >> choiceString;

    int choiceInt;
    choiceInt = isInt(choiceString, 1, maxNum);

    if (choiceInt == 1) {
        int clayrObject = rand() % 4 + 1;
        if (clayrObject == 1) {
            std::cout << "You have found the Disreputable Dog, a powerful creature with hints of both Charter \n";
            std::cout << "and Free Magic. She's a great companion and friend.\n\n";
            object = DOG;
        }
        else if (clayrObject == 2) {
            std::cout << "You have found the Dark Mirror. It can be used in Death to see into the past.\n\n";
            object = MIRROR;
        }
        else if (clayrObject == 3) {
            std::cout << "You have found the Book of Remembrance and Forgetting. It has helped Lirael understand \n";
            std::cout << "her role as a Remembrancer.\n\n";
            object = BOOK;
        }
        else if (clayrObject == 4) {
            std::cout << "You have found an emergency mouse, used by the Clayr Librarians to send for help \n";
            std::cout << "when they find themselves in danger.\n\n";
            object = MOUSE;
        }
    }
    if (choiceInt == 4) {
        //Advice from Sanar and Ryelle.
        std::cout << "'Lirael, daughter of the Clayr, we have Seen what is to come and you must hurry!' say Sanar and\n"
                  "Ryelle, the current Voice of the Nine Day Watch. Gather all you need and go as quickly as you can \n"
                  "to the Northern Border. In most of the Futures we see, this is where you will face the threat. \n"
                  "For the entire kingdom's sake, we hope you are victorious.\n\n";
    }
    return choiceInt;
}