//
// Created by serwu on 14.04.2022.
//

#include <iostream>
#include <valarray>
#include "MyBinaryHeap.h"
#include "../FileManagement.h"

void MyBinaryHeap::deleteLast() {
    if (size > 0) {
        body->deleteRear();
        size--;
    }
}

void MyBinaryHeap::add(int container) {
    body->addRear(container);
    size++;
}

void MyBinaryHeap::deleteRoot() {
    if (size > 0) {
        body->deleteFront();
        size--;
    }
}

void MyBinaryHeap::regainHeapAttributes() {
    //iterates trough array until making no change
    //when function finds bigger than it's father it replaces them
    //when both sons are bigger than father function chooses bigger son to change with father

    if (size > 3) {
        for (int i = size / 2; i >= 0; --i) {
            heapify(i);
        }
    } else {
        int max = INT16_MIN;
        int pos = 0;
        for (int i = 0; i < size; i++) {
            if (body->get(i) > max) {
                max = body->get(i);
                pos = i;
            }
            if (pos > 0)
                body->swap(0, pos);
        }
    }
}

void MyBinaryHeap::show() {
    //simple show function with extra endlines to simulate binary heap appearance
    //body->show();

    if (size > 3) {
        std::cout << std::endl;
        int depth = getDepth();
        int spaces = 1;

        for (int i = 0; i < depth - 1; i++) {
            spaces *= 2;
            spaces++;
        }

        int powersOfTwo = 1;
        int i = 0;
        while (i < depth) {
            std::cout << std::string(spaces / 2, ' ');
            for (int j = 0; j < powersOfTwo; j++) {
                std::cout << body->get(i) << std::string(spaces, ' ');
                i++;
            }

            spaces--;
            spaces = spaces / 2;

            powersOfTwo *= 2;
            std::cout << std::endl;
        }
        for (; i < size; i++) {
            std::cout << body->get(i) << " ";
        }
        std::cout << std::endl;
    } else if (size > 0) {
        std::cout << " " << body->get(0) << "\n";
        for (int i = 1; i < size; i++)
            std::cout << body->get(i) << " ";
        std::cout << std::endl;
    }
}

int MyBinaryHeap::findFirst(int number) {
    return body->findFirst(number);
}

void MyBinaryHeap::deleteAll() {
    body->deleteAll();
    size = 0;
}

void MyBinaryHeap::readFromFile(std::string fileName) {
    //opening file, reading size, reading and adding elements from file
    FileManagement myFileManager;
    myFileManager.openFile('i', fileName);
    int howManyElements = myFileManager.getLine();
    for (int i = 0; i < howManyElements; i++) {
        int readFromFile;
        readFromFile = myFileManager.getLine();
        add(readFromFile);
    }
    myFileManager.closeFile();
}

int MyBinaryHeap::getDepth() {
    int powersOfTwo = 1;
    int counter = 0;
    int i = 0;

    while (i <= size) {
        counter++;
        i += powersOfTwo;
        powersOfTwo *= 2;
    }

    return counter;
}

void MyBinaryHeap::heapify(int position) {
    int left = 2 * position + 1;
    int right = 2 * position + 2;
    int largest = position;

    if (left < size && body->get(left) > body->get(largest)) {
        largest = left;
    }

    if (right < size && body->get(right) > body->get(largest)) {
        largest = right;
    }

    if (largest != position) {
        body->swap(largest, position);

        heapify(largest);
    }
}
