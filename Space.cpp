/************************************************************************************
** Program name: 162 Final Project
** Author: Kristin Wood
** Date: 3/14/2018
** Description: This is an abstract base class for Spaces. It includes pointers to
**      Spaces in the four cardinal directions, as well as above and below. It also
**      includes an object, health change and name. It has a constructor, get and
**      set functions and a virtual menu function.
************************************************************************************/

#include "Space.hpp"

Space::Space() {
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    above = nullptr;
    below = nullptr;
    healthChange = 0;
    name = "";
}

void Space::setTop(Space* space) {
    top = space;
}

void Space::setBottom(Space* space) {
    bottom = space;
}

void Space::setLeft(Space* space) {
    left = space;
}

void Space::setRight(Space* space) {
    right = space;
}

void Space::setBelow(Space* space) {
    below = space;
}

void Space::setAbove(Space* space) {
    above = space;
}

Space* Space::getTop() {
    return top;
}

Space* Space::getBottom() {
    return bottom;
}

Space* Space::getLeft() {
    return left;
}

Space* Space::getRight() {
    return right;
}

Space* Space::getBelow() {
    return below;
}

Space* Space::getAbove() {
    return above;
}

void Space::setObject(PackItems obj) {
    object = obj;
}

void Space::setHealthChange(int health) {
    healthChange = health;
}

PackItems Space::getObject() {
    return object;
}

int Space::getHealthChange() {
    return healthChange;
}

std::string Space::getName() {
    return name;
}