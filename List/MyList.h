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

    void addPrimalElement(ListElement *);

public:
    void addRear(int);

    void addFront(int);

    void addOnPosition(int, int);

    void deleteRear();

    void deleteFront();

    void deletePos(int);

    int getSize();

    int getHead();

    int getContainer(int);

    int findFirst(int);

    int show();

    void readFromFile(std::string);

    void deleteAll();
};


#endif //MAIN_CPP_MYLIST_H
