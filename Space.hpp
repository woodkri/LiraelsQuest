/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This is an abstract base class for Spaces. It includes pointers to
**      Spaces in the four cardinal directions, as well as above and below. It also
**      includes an object, health change and name. It has a constructor, get and
**      set functions and a virtual menu function.
************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "Lirael.hpp"

class Space {
protected:
    Space* top;
    Space* bottom;
    Space* left;
    Space* right;
    Space* below;
    Space* above;
    PackItems object;
    int healthChange;
    std::string name;
public:
    Space();
    virtual int menu() = 0;
    void setTop(Space*);
    void setBottom(Space*);
    void setLeft(Space*);
    void setRight(Space*);
    void setBelow(Space*);
    void setAbove(Space*);
    Space* getTop();
    Space* getBottom();
    Space* getLeft();
    Space* getRight();
    Space* getBelow();
    Space* getAbove();
    void setObject(PackItems);
    void setHealthChange(int);
    PackItems getObject();
    int getHealthChange();
    std::string getName();
};


#endif //SPACE_HPP
