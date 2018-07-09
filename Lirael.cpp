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

#include <iostream>
#include "Lirael.hpp"
#include "ClayrGlacier.hpp"

Lirael::Lirael() {
    maxStrength = 50;
    strength = 50;
    location = nullptr;
    hasBells = false;
    hasMirror = false;
    hasDog = false;
}
/************************************************************************************
 * This function takes a PackItems variable as a parameter and adds it to the pack.
 * It updates bools for certain items that will be used in the game and allows the
 * user to remove one of the items already in the pack to make room if there is not
 * enough space.
************************************************************************************/
void Lirael::addItem(PackItems item) {
    if (pack.size() < 5) {
        pack.push_back(item);
        if (item == BELLS) {
            hasBells = true;
        }
        else if (item == MIRROR) {
            hasMirror = true;
        }
        else if (item == DOG) {
            hasDog = true;
        }
    }
    else {
        std::cout << "\nLirael's pack is too full. Do you want to remove an item to make room?\n\n";
        std::cout << "Y for yes, N for no: ";
        char userChoice;
        std::cin >> userChoice;
        if (userChoice == 'Y' || userChoice == 'y') {
            std::cout << "\nPlease enter the number of the item you would like to remove.\n";
            displayItems();
            std::string userString;
            std::cin >> userString;
            int userInt = isInt(userString, 1, 5);
            removeItem(userInt-1);
            pack.push_back(item);
            //Reset bools and go through pack to see what is there.
            hasBells = false;
            hasMirror = false;
            hasDog = false;
            for (auto i : pack) {
                if (i == BELLS) {
                    hasBells = true;
                }
                else if (i == MIRROR) {
                    hasMirror = true;
                }
                else if (i == DOG) {
                    hasDog = true;
                }
            }
        }
    }
}

/************************************************************************************
 * This function displays the items in Lirael's pack.
************************************************************************************/
void Lirael::displayItems() {
    for (int i = 0; i < pack.size(); i++) {
        std::cout << i+1 << ". ";
        if (pack[i] == BELLS) {
            std::cout << "Bell Bandolier\n";
        }
        else if (pack[i] == SWORD) {
            std::cout << "Sword\n";
        }
        else if (pack[i] == DOG) {
            std::cout << "Disreputable Dog\n";
        }
        else if (pack[i] == MIRROR) {
            std::cout << "Dark Mirror\n";
        }
        else if (pack[i] == SKIN) {
            std::cout << "Charter Skin\n";
        }
        else if (pack[i] == BOOK) {
            std::cout << "Book of Remembrance and Forgetting\n";
        }
        else if (pack[i] == MOUSE) {
            std::cout << "Emergency Mouse\n";
        }
    }
}

/************************************************************************************
 * This function takes an int as a parameter and removes the item at that index from
 * the pack.
************************************************************************************/
void Lirael::removeItem(int itemIndex) {
    if (itemIndex <= pack.size()) {
        pack.erase(pack.begin() + itemIndex);
    }
    else {
        std::cout << "The item could not be removed.\n";
    }
}

/************************************************************************************
 * This function displays the bells in Lirael's bandolier and returns a Bell of the
 * user's choice.
************************************************************************************/
Bells Lirael::useBell() {
    std::string bellChoice;
    std::cout << "\nWhich bell would you like to use?\n";
    std::cout << "1. Ranna, the Sleeper\n";
    std::cout << "2. Mosrael, the Waker\n";
    std::cout << "3. Kibeth, the Walker\n";
    std::cout << "4. Dyrim, the Speaker\n";
    std::cout << "5. Belgaer, the Thinker\n";
    std::cout << "6. Saraneth, the Binder\n";
    std::cout << "7. Astarael, the Sorrowful\n";
    std::cin >> bellChoice;
    int bell = isInt(bellChoice, 1, 7);
    if (bell == 1) {
        return RANNA;
    }
    else if (bell == 2) {
        return MOSRAEL;
    }
    else if (bell == 3) {
        return KIBETH;
    }
    else if (bell == 4) {
        return DYRIM;
    }
    else if (bell == 5) {
        return BELGAER;
    }
    else if (bell == 6) {
        return SARANETH;
    }
    else if (bell == 7) {
        return ASTARAEL;
    }
}

/************************************************************************************
 * This function changes the maxStrength variable and is used to change the capacity
 * of Lirael's strength/health.
************************************************************************************/
void Lirael::setMaxStrength(int maxStrength){
    this->maxStrength = maxStrength;
}  //When upper limit needs to be increased.

int Lirael::getMaxStrength() {
    return maxStrength;
}

/************************************************************************************
 * This function takes a positive or negative int as a parameter and adds it to
 * Lirael's current strength. If the strength is greater than her maxStrength, then
 * strength is set to maxStrength.
************************************************************************************/
void Lirael::addStrength(int str) {
    strength += str;
    if (strength > maxStrength) {
        strength = maxStrength;
    }
}

int Lirael::getStrength() {
    return strength;
}

void Lirael::setLocation(Space* location) {
    this->location = location;
}

Space* Lirael::getLocation() {
    return location;
}

bool Lirael::getBells() {
    return hasBells;
}

bool Lirael::getMirror() {
    return hasMirror;
}

bool Lirael::getDog() {
    return hasDog;
}