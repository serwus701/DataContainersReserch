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
