//
// Created by serwu on 21.04.2022.
//

#include <iostream>
#include "MyRedBlackTree.h"
#include "../Array/MyArray.h"

MyRedBlackTree::MyRedBlackTree() {
    RBTElement *guardElement = new RBTElement(nullptr, guardElement, guardElement, 0, 'b');
}


void MyRedBlackTree::addElement(int container) {
    RBTElement *newElement = new RBTElement(newElement, guard, guard, container, 'r');
    if (size > 0) {
        RBTElement *tempElement = root;
        while (tempElement != guard) {
            if (container >= tempElement->getContainer()) {
                if (tempElement->getRight() == guard) {
                    tempElement->setRight(newElement);
                    newElement->setFather(tempElement);
                    break;
                } else
                    tempElement = tempElement->getRight();
            } else if (tempElement->getLeft() == guard) {
                tempElement->setLeft(newElement);
                newElement->setFather(tempElement);
                break;
            } else
                tempElement = tempElement->getLeft();
        }
        size++;
    }
    if (size == 0) {
        root = newElement;
        size++;
    }
}

void MyRedBlackTree::deleteRoot() {
    RBTElement *newRoot = root;
    if (newRoot->getLeft() != guard) {
        newRoot = newRoot->getLeft();
        while (newRoot->getRight() != guard)
            newRoot = newRoot->getRight();
        if (root->getRight() != guard)
            root->getRight()->setFather(newRoot);
        root->getLeft()->setFather(newRoot);
        delete root;
        root = newRoot;
        root->setFather(nullptr);
    }
    if (newRoot->getRight() != guard)
        delete root;
    root = newRoot;
    root->setFather(nullptr);
}

void MyRedBlackTree::show() {
    int toShow[size];
    RBTElement *  temp = root;
    treeToArray(temp, toShow, 0);

    for (int eachElement : toShow) {
        std::cout << eachElement <<std::endl;
    }
}

int MyRedBlackTree::getDepth() {
    int depth = 0;
    if (size > 0) {
        RBTElement *iteratingElement = root;
        while (iteratingElement->getRight() != guard) {
            iteratingElement = iteratingElement->getRight();
            depth++;
        }
        return depth + 1;

    } else
        return 0;
}

void MyRedBlackTree::treeToArray(RBTElement * currentNode, int * array, int  position) {
    array[position] =  currentNode->getContainer();

    if(currentNode->getLeft() != guard)
        treeToArray(currentNode->getLeft(), array, 2 * position + 1);

    if(currentNode->getRight() != guard)
        treeToArray(currentNode->getRight(), array, 2 * position + 2);
}
