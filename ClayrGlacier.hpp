/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a randomized item to the pack, obtain healing, move to another part of
**      the kingdom, or speak with the Voice of the Watch for a hint.
************************************************************************************/

#ifndef INC_162FINALPROJECT_CLAYRGLACIER_HPP
#define INC_162FINALPROJECT_CLAYRGLACIER_HPP

#include "Space.hpp"

class ClayrGlacier : public Space {
private:

public:
    ClayrGlacier();
    int menu();
};


#endif //INC_162FINALPROJECT_CLAYRGLACIER_HPP
