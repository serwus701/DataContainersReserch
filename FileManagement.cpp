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

void FileManagement::closeFile() {
    file.close();
}

void FileManagement::writeNum(double toWrite) {
    file << toWrite << " ";
}

void FileManagement::writeStr(std::string toWrite) {
    file << toWrite;
}
