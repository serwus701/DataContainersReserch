//
// Created by Michał on 13.03.2022.
//

#include <iostream>
#include "MyList.h"
#include "../FileManagement.h"

void MyList::addPrimalElement(ListElement *primalElement) {
    //used in case of creating first element
    head = primalElement;
    tail = primalElement;
    size = 1;
}

void MyList::addRear(int element) {
    //creating new element, stacking it, rearranging pointers to be pointed and to point adjacent elements
    //setting new tail pointer
    auto *newElement = new ListElement;

    if (size == 0) {
        addPrimalElement(newElement);
        newElement->setContainer(element);
        return;
    }

    ListElement *myTail = tail;
    myTail->setNext(newElement);
    newElement->setPrevious(tail);
    newElement->setContainer(element);
    tail = newElement;

    size++;
}

void MyList::addFront(int element) {
    //creating new element, stacking it, rearranging pointers to be pointed and to point adjacent elements
    //setting new head pointer
    auto newElement = new ListElement;

    if (size == 0) {
        addPrimalElement(newElement);
        newElement->setContainer(element);
        return;
    }

    ListElement *myHead = head;
    myHead->setPrevious(newElement);
    newElement->setNext(head);
    newElement->setContainer(element);
    head = newElement;

    size++;
}

int MyList::getHead() {
    return head->element();
}

int MyList::getSize() {
    return size;
}

ListElement *MyList::getElementPtr(int position) {
    //used to get pointer of an element
    if (position < 0)
        return nullptr;
    if (position > size - 1)
        return nullptr;

    ListElement *tempElement = head;
    for (int i = 0; i < position; i++) {
        tempElement = tempElement->getNext();
    }
    return tempElement;
}

void MyList::deletePos(int position) {
    //iterate trough list until reaching given position. if so deletes it and restores pointers
    if ((position > 0) && (position < size - 1) && (size > 0)) {

        if (position == size - 1) {
            deleteRear();
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }

        ListElement *temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->getNext();
        }

        ListElement *myNext = temp->getNext();
        ListElement *myPrevious = temp->getPrevious();

        myPrevious->setNext(myNext);
        myNext->setPrevious(myPrevious);

        delete temp;

        size--;

    }
    if (position == 0 && size > 0)
        deleteFront();
    else if (position == size - 1 && size > 0)
        deleteRear();
}

int MyList::getContainer(int position) {
    //iterating trough entire list until reaching given position. returnes object on that position
    ListElement *tempPointer = getElementPtr(position);
    if (tempPointer != nullptr)
        return tempPointer->getContainer();
    else
        return NULL;
}

void MyList::addOnPosition(int position, int element) {
    //iterate trough list until reaching given position. if so adds there new element and restores pointers
    if (position == size) {
        addRear(element);
        return;
    }
    if (position == 0) {
        addFront(element);
        return;
    }

    ListElement *currentPositionPtr = getElementPtr(position);

    if (currentPositionPtr != nullptr) {
        auto newElement = new ListElement;

        newElement->setNext(currentPositionPtr);
        newElement->setPrevious(currentPositionPtr->getPrevious());
        newElement->setContainer(element);

        currentPositionPtr->setPrevious(newElement);
        newElement->getPrevious()->setNext(newElement);
        size++;
    }
}

void MyList::deleteRear() {
    //deletes rear object and restores pointers
    if (size == 1) {
        delete tail;
        tail = nullptr;
        head = nullptr;
        size--;
    } else if (size > 0) {
        ListElement *temp = tail;
        tail = tail->getPrevious();
        tail->setNext(nullptr);
        size--;
        delete temp;
    }
}

void MyList::deleteFront() {
    //deletes front object and restores pointers
    if (size == 1) {
        delete tail;
        tail = nullptr;
        head = nullptr;
        size--;
    } else if (size > 0) {
        ListElement *temp = head;
        head = head->getNext();
        head->setPrevious(nullptr);
        size--;
        delete temp;
    }
}

int MyList::show() {
    //iterates trough array and reads its containers
    if (size > 0) {
        ListElement *iterator = head;
        std::cout << "List: ";
        while (iterator->getNext() != nullptr) {
            std::cout << iterator->getContainer() << " ";
            iterator = iterator->getNext();
        }
        std::cout << iterator->getContainer() << " ";
        std::cout << std::endl;
    }
}

int MyList::findFirst(int number) {
    //iterates trough array until finding container matching given value
    ListElement *iterator = head;
    int i = 0;
    while (iterator->getNext() != nullptr) {
        if (iterator->getContainer() == number)
            return i;
        iterator = iterator->getNext();
        i++;
    }
    return NULL;
}

void MyList::deleteAll() {
    //iterates trough list and deletes every element
    ListElement *tempPtr = head;
    if (tempPtr != nullptr) {
        while (tempPtr->getNext() != nullptr) {
            tempPtr = tempPtr->getNext();
            delete tempPtr->getPrevious();
        }
        delete tempPtr;
    }
}

void MyList::readFromFile(std::string fileName) {
    //opening file, reading size, reading and adding elements from file
    FileManagement myFileManager;
    myFileManager.openFile('i', fileName);
    int howManyElements = myFileManager.getLine();
    for (int i = 0; i < howManyElements; i++) {
        int readFromFile;
        readFromFile = myFileManager.getLine();
        addRear(readFromFile);
    }
    myFileManager.closeFile();
}

