//
// Created by serwu on 17.04.2022.
//
#include <iostream>
#include "FileManagement.h"
#include "Interface.h"

void FileManagement::openFile(char inputOutput, std::string fileName) {
    if(inputOutput == 'i'){
        file.open(fileName + ".txt", std::ios::in);
    } else{
        file.open(fileName + ".txt", std::ios::app);
    }
}

void FileManagement::randNumbersToFile(int size) {
    for(int i = 0; i < size; i++){
        file << (rand() % 200 - 100);
        file << std::endl;
    }
}

void FileManagement::closeFile() {
    file.close();
}

int FileManagement::getLine() {
    std::string strNumber;
    file >> strNumber;
    return stoi(strNumber);
}

void FileManagement::writeNum(double toWrite) {
    file << toWrite << " ";
}

void FileManagement::writeStr(std::string toWrite) {
    file << toWrite;
}
