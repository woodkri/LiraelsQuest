/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a sword to the pack, obtain a golden hand (increased health capacity),
**      and move to another part of the kingdom.
************************************************************************************/

#ifndef INC_162FINALPROJECT_BELISAERE_HPP
#define INC_162FINALPROJECT_BELISAERE_HPP

#include "Space.hpp"

class Belisaere : public Space {
private:

public:
    Belisaere();
    int menu();
};


#endif //INC_162FINALPROJECT_BELISAERE_HPP
