//
// Created by serwu on 21.04.2022.
//

#include "MyRedBlackTree.h"

MyRedBlackTree::MyRedBlackTree() {
    RBTElement *guardElement = new RBTElement(nullptr, guardElement, guardElement, 0, 'b');
}


void MyRedBlackTree::addElement(int container) {
    RBTElement *newElement = new RBTElement(newElement, guard, guard, container, 'r');
    if (size == 0) {
        root = newElement;
        size++;
    }
    if (size > 0) {
        RBTElement *tempElement = root;
        while (tempElement != guard) {
            if (container >= tempElement->getContainer()) {
                if (tempElement->getRight() == guard) {
                    tempElement->setRight(newElement);
                    newElement->setFather(tempElement);
                } else
                    tempElement = tempElement->getRight();
            } else if (tempElement->getLeft() == guard) {
                tempElement->setLeft(newElement);
                newElement->setFather(tempElement);
            } else
                tempElement = tempElement->getLeft();
        }
    }
}

//SPRAWDZ WSZYSTKO!!!!!!!!!!
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
