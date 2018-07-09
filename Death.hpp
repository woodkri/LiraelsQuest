/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      use the Dark Mirror for a message, walk through Death, or move back to the
**      last space she was in.
************************************************************************************/

#ifndef INC_162FINALPROJECT_DEATH_HPP
#define INC_162FINALPROJECT_DEATH_HPP


#include "Space.hpp"

class Death : public Space {
private:

public:
    Death();
    int menu();
};


#endif //INC_162FINALPROJECT_DEATH_HPP
