/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This class is the main character of the game. It defines enums for
**      items she can carry in her pack, as well as the 7 bells in her bandolier.
**      Within the class definition, there are variables for strength, maximum
**      strength, a vector of PackItems, a pointer to her location, and bools for
**      if she has bells, a dark mirror, and the Disreputable Dog. She also has get
**      and set functions, functions to add, remove and display her items, and use
**      her bells.
************************************************************************************/

#ifndef LIRAEL_HPP
#define LIRAEL_HPP

#include <vector>
#include "isInt.hpp"
class Space;

enum PackItems {BELLS, SWORD, DOG, MIRROR, SKIN, BOOK, MOUSE};
enum Bells {RANNA, MOSRAEL, KIBETH, DYRIM, BELGAER, SARANETH, ASTARAEL};

class Lirael {
private:
    int strength;
    int maxStrength;
    std::vector<PackItems> pack;
    Space* location;
    bool hasBells;
    bool hasMirror;
    bool hasDog;
public:
    Lirael();
    void addItem(PackItems);
    void removeItem(int);
    void displayItems();
    Bells useBell();
    void setMaxStrength(int);  //When upper limit needs to be increased.
    int getMaxStrength();
    void addStrength(int);
    int getStrength();
    void setLocation(Space*);
    Space* getLocation();
    bool getBells();
    bool getMirror();
    bool getDog();
};


#endif //LIRAEL_HPP
