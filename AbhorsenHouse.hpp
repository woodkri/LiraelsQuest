/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a bell bandolier to the pack, take a bath to regain health, move to
**      another part of the kingdom, and get a random piece of advice from a cat
**      who lives in the house.
************************************************************************************/

#ifndef INC_162FINALPROJECT_ABHORSENHOUSE_HPP
#define INC_162FINALPROJECT_ABHORSENHOUSE_HPP


#include "Space.hpp"

class AbhorsenHouse : public Space {
private:

public:
    AbhorsenHouse();
    int menu();
    void mogget();
};


#endif //INC_162FINALPROJECT_ABHORSENHOUSE_HPP
