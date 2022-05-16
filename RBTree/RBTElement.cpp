//
// Created by serwu on 21.04.2022.
//

#include "RBTElement.h"

RBTElement::RBTElement(RBTElement * myFather, RBTElement * myLeft, RBTElement * myRight, int myContainer, char myColour) {
    father = myFather;
    left = myLeft;
    right = myRight;
    container = myContainer;
    colour = myColour;
}

void RBTElement::setFather(RBTElement * myFather) {
    father = myFather;
}

void RBTElement::setLeft(RBTElement * myLeft) {
    left = myLeft;
}

void RBTElement::setRight(RBTElement * myRight) {
    right = myRight;
}

void RBTElement::setColour(char myColour) {
    if (myColour == 'r')
        colour = 'r';
    if(myColour == 'b')
        colour = 'b';
}

int RBTElement::getContainer() {
    return container;
}

RBTElement *RBTElement::getLeft() {
    return left;
}

RBTElement *RBTElement::getRight() {
    return right;
}
