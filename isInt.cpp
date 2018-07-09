/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This file was created to validate integer input. It is designed to
**      be reusable by including parameters for the minimum and maximum numbers
**      allowed. The function takes a string as a parameter also, and if the string
**      is acceptable input, returns it as an int.
************************************************************************************/

#include "isInt.hpp"

int isInt(std::string numChosen, int minNum, int maxNum) {
    bool status = true;
    int converted;
    do {
        //Reset status from previous loop
        status = true;

        //Check if all characters are ints
        for (int i = 0; i < numChosen.length(); i++) {
            if (!isdigit(numChosen[i])) {
                status = false;
            }
        }

        //Convert string to int
        if (status == true) {
            converted = stoi(numChosen);
        }
        if (converted < minNum || converted > maxNum) {
            status = false;
        }

        //Prompt user if input was invalid
        if (status == false) {
            std::cout << "That's not right. Please try again: \n";
            std::cin >> numChosen;
        }
    } while (status == false);

    return converted;
}