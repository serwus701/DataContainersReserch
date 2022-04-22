//
// Created by serwu on 14.04.2022.
//

#include <iostream>
#include "MyBinaryHip.h"

void MyBinaryHip::deleteLast() {
    myTree->deleteRear();
}

void MyBinaryHip::add(int container) {
    myTree->addRear(container);
    size++;
}

void MyBinaryHip::deleteRoot() {
    myTree->deleteFront();
    size--;
}

void MyBinaryHip::regainHipAttributes() {
    //iterates trough array until making no change
    //when function finds bigger than it's father it replaces them
    //when both sons are bigger than father function chooses bigger son to change with father
    bool keepGoing = true;
    while (keepGoing) {
        keepGoing = false;
        for (int i = 0; i < size / 2; i++) {
            if (i * 2 + 2 < size) {

                int father = myTree->get(i);
                int left = myTree->get(2 * i + 1);
                int right = myTree->get(2 * i + 2);

                if(left > father){
                    if(right > father){
                        if(left > right){
                            myTree->swap(i, 2 * i + 1);
                            keepGoing = true;
                        } else{
                            myTree->swap(i, 2 * i + 2);
                            keepGoing = true;
                        }
                    } else{
                        myTree->swap(i, 2 * i + 1);
                        keepGoing = true;
                    }
                }
            } else if (i * 2 + 1 < size){
                if(myTree->get(2 * i + 1) < myTree->get(i))
                    myTree->swap(myTree->get(2 * i + 1), myTree->get(i));
            }

        }
    }
}

void MyBinaryHip::show() {
    //simple show function with extra enters to simulate binary heap appearance
    std::cout<<std::endl;
    int twos = 1;
    int whereEnter = 0;
    for (int i = 0; i < size; i++) {
        std::cout<<myTree->get(i)<<" ";
        if(i == whereEnter){
            twos *= 2;
            whereEnter += twos;
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}

int MyBinaryHip::findFirst(int number) {
    return myTree->findFirst(number);
}

void MyBinaryHip::deleteAll() {
    myTree->deleteAll();
}

void MyBinaryHip::readFromFile(std::string fileName) {
    myTree->readFromFile(fileName);
}
