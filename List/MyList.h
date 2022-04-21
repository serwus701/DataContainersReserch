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

    ListElement *getFullElement(int);

    void addPrimalElement(ListElement *);

public:
    void addRear(int);

    void addFront(int);

    void addPos(int, int);

    void deleteRear();

    void deleteFront();

    void deletePos(int);

    int getSize();

    int getHead();

    int getElement(int);

    int findFirst(int);

    int show();

    void deleteAll();
};


#endif //MAIN_CPP_MYLIST_H
