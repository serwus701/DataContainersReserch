//
// Created by Michał on 13.03.2022.
//

#ifndef MAIN_CPP_MYLIST_H
#define MAIN_CPP_MYLIST_H

#include "ListElement.h"


class MyList {
private:
    int size = 0;
    ListElement *head;
    ListElement *tail;

    ListElement *getElementPtr(int);

    void addPrimalElement(ListElement *);//adding first element

public:
    void addRear(int);

    void addFront(int);

    void addOnPosition(int, int);

    void deleteRear();

    void deleteFront();

    void deletePos(int);

    int getSize();//returns size of structure

    int getHead();//returns element from the front of the structure

    int getContainer(int);//returns element at the given position

    int findFirst(int);//returns position of first element with equal to given value

    int show();

    void readFromFile(std::string);//file input

    void deleteAll();//delete structure
};


#endif //MAIN_CPP_MYLIST_H
