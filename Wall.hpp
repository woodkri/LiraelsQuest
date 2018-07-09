/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is derived from the Space class, and includes options to
**      add a charter skin to the pack, approach a figure, or move to another part
**      of the kingdom.
************************************************************************************/

#ifndef INC_162FINALPROJECT_WALL_HPP
#define INC_162FINALPROJECT_WALL_HPP


#include "Space.hpp"

class Wall : public Space {
private:

public:
    Wall();
    int menu();
};


#endif //INC_162FINALPROJECT_WALL_HPP
