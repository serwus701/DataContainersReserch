//
// Created by Michał on 13.03.2022.
//

#include <iostream>
#include "MyArray.h"
#include "../FileManagement.h"


void MyArray::addRear(int element) {
//creating a new functionManager, rewriting each element with pointers and adding last element
    size++;
    int *newTab = new int[size];
    int *toDelete = tabPointer;

    if (size > 0) {
        int *tempPointer = newTab;
        for (int i = 0; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }
    }
    newTab[size - 1] = element;

    tabPointer = newTab;
    delete toDelete;
}

void MyArray::addFront(int element) {
    //creating a new functionManager, adding new first element and rewriting each element with pointers until the end
    size++;
    int *newTab = new int[size];
    int *toDelete = tabPointer;

    if (size > 1) {
        int *tempPointer = newTab;
        tempPointer++;
        for (int i = 0; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }
    }
    newTab[0] = element;

    tabPointer = newTab;
    delete toDelete;
}

void MyArray::addOnPos(int position, int container) {
//creating a new functionManager, rewriting each element until certain position, then inserting extra one and rewriting until the end

    if (position == 0) {
        addFront(container);
        return;
    }
    if (position == size - 1) {
        addRear(container);
        return;
    }

    if ((position < size - 1) && (position > 0)) {
        size++;
        int *newTab = new int[size];
        int *toDelete = tabPointer;

        int *tempPointer = newTab;
        for (int i = 0; i < position; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        *tempPointer = container;
        tempPointer++;

        for (int i = position; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer = newTab;
        delete toDelete;
    }
}

void MyArray::deleteRear() {
    //creating a new functionManager, rewriting each element but the last one
    if (size > 0) {
        size--;
        int *newTab = new int[size];
        int *toDelete = tabPointer;
        int *tempPointer = newTab;

        for (int i = 0; i < size; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer = newTab;
        delete[] toDelete;
    }
}

void MyArray::deleteFront() {
//creating a new functionManager, skipping first one, and rewriting each element with pointers
    if (size > 0) {
        size--;
        int *newTab = new int[size];
        int *toDelete = tabPointer;
        int *tempPointer = newTab;
        tabPointer++;
        for (int i = 0; i < size; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }
        tabPointer = newTab;
        delete[] toDelete;
    }
}

void MyArray::deleteOnPos(int position) {
//creating a new functionManager, rewriting each element until certain position, then skipping one position and rewriting until the end
    if ((position < size) && (position > -1)) {
        int *newTab = new int[size - 1];
        int *toDelete = tabPointer;
        int *tempPointer = newTab;
        for (int i = 0; i < position; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer++;

        for (int i = position; i < size - 1; i++) {
            *tempPointer = *tabPointer;
            tempPointer++;
            tabPointer++;
        }

        tabPointer = newTab;
        delete[] toDelete;
        size--;
    }

}

void MyArray::swap(int pos1, int pos2) {
    //copying elements from both positions and pasting them on swapped positions
    if ((pos1 > -1) && (pos1 < size)) {
        if ((pos2 > -1) && (pos2 < size)) {
            int *pos1Ptr = tabPointer + pos1;
            int *pos2Ptr = tabPointer + pos2;
            int temp = *pos1Ptr;
            *pos1Ptr = *pos2Ptr;
            *pos2Ptr = temp;

        }
    }

}

int MyArray::findFirst(int value) {
//inspecting every element until finding correct one
    int *tempPointer = tabPointer;
    for (int i = 0; i < size; i++) {
        if (*(tempPointer + i) == value)
            return i;
    }
    return -1;//returning -1 if there is no such element
}

int MyArray::get(int position) {
    return *(tabPointer + position);
}

int MyArray::getSize() {
    return size;
}

void MyArray::show() {
    //inspecting and writing every element
    int *tempPointer = tabPointer;

    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << *tempPointer << " ";
        tempPointer++;
    }
    std::cout << std::endl;
}

void MyArray::deleteAll() {
    //deleting entire container
    if (tabPointer != nullptr)
        delete[] tabPointer;
}

void MyArray::readFromFile(std::string fileName) {
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

int MyArray::getFromRear(int position) {
    return *(tabPointer + size - 1 - position);
}
