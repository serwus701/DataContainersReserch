//
// Created by serwu on 14.04.2022.
//

#include <iostream>
#include "MyBinaryTree.h"

void MyBinaryTree::deleteLast() {
    myTree->deleteRear();
}

void MyBinaryTree::add(int container) {
    myTree->addRear(container);
    size++;
}

void MyBinaryTree::deleteRoot() {
    myTree->deleteFront();
    size--;
}

void MyBinaryTree::regainHipAttributes() {
    bool keepGoing;
    do {
        keepGoing = false;
        for (int i = 0; i < size / 2; i++) {
            if (i * 2 + 2 < size) {
                if (myTree->get(i) > myTree->get(2 * i + 2)) {
                    myTree->swap(i, 2 * i + 2);
                    keepGoing = true;
                }
            }

        }
    } while (keepGoing);
}

void MyBinaryTree::show() {
    myTree->show();
}

int MyBinaryTree::findFirst(int number) {
    return myTree->findFirst(number);
}

void MyBinaryTree::deleteAll() {
    myTree->deleteAll();
}
