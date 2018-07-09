/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This file was created to validate integer input. It is designed to
**      be reusable by including parameters for the minimum and maximum numbers
**      allowed. The function takes a string as a parameter also, and if the string
**      is acceptable input, returns it as an int.
************************************************************************************/

#include <iostream>
#include <string>

#ifndef ISINT_HPP
#define ISINT_HPP

int isInt(std::string numChosen, int minNum, int maxNum);

#endif //ISINT_HPP
