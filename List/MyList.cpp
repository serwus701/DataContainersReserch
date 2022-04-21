//
// Created by Michał on 13.03.2022.
//

#include <iostream>
#include "MyList.h"

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

ListElement *MyList::getFullElement(int position) {
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
    if ((position > -1) && (position < size) && (size > 0)) {

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
}

int MyList::getElement(int position) {
    ListElement *tempPointer = getFullElement(position);
    if (tempPointer != nullptr)
        return tempPointer->getContainer();
    else
        return NULL;
}

void MyList::addPos(int position, int element) {
    ListElement *tempPointer = getFullElement(position);

    if (tempPointer != nullptr) {
        auto tempElement = new ListElement;

        if(size == 0){
            addPrimalElement(tempElement);
            tempElement->setContainer(element);
            return;
        }

        tempElement->setNext(tempPointer->getNext());
        tempElement->setPrevious(tempPointer->getPrevious());
        tempElement->setContainer(element);
        size++;
    }
}

void MyList::deleteRear() {
    if(size > 0){
        ListElement *temp = tail;
        tail = tail->getPrevious();
        tail->setNext(nullptr);
        size--;
        delete temp;
    }
}

void MyList::deleteFront() {
    if(size > 0){
        ListElement *temp = head;
        head = head->getNext();
        head->setPrevious(nullptr);
        size--;
        delete temp;
    }
}

int MyList::show() {
    if(size > 0) {
        ListElement *iterator = head;
        while (iterator->getNext() != nullptr) {
            std::cout << iterator->getContainer() << " ";
            iterator = iterator->getNext();
        }
        std::cout << iterator->getContainer() << " ";
        std::cout << std::endl;
    }
}

int MyList::findFirst(int number) {
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
    ListElement * tempPtr = head;
    if(tempPtr != nullptr){
        while (tempPtr->getNext() != nullptr){
            tempPtr = tempPtr->getNext();
            delete tempPtr->getPrevious();
        }
        delete tempPtr;
    }
}

