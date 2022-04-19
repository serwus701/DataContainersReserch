//
// Created by serwu on 17.04.2022.
//
#include <iostream>
#include "FileManagement.h"
#include "Interface.h"

void FileManagement::createInputFile() {
    inputNumbers.open("inputNumbers.txt");
    if (!inputNumbers)
        std::cout<<"File has not been created.";
}

void FileManagement::randNumbersToFile() {
    int number;
    for(int i = 0; i < size; i++){
        number = rand() % 200 - 100;
        inputNumbers << number;
        inputNumbers << std::endl;
    }
}

void FileManagement::closeInputFile() {
    inputNumbers.close();
}

int FileManagement::getLine() {
    std::string strNumber;
    inputNumbers >> strNumber;
    return stoi(strNumber);
}

void FileManagement::createOutputFile()  {
        outputNumbers.open("outputNumbers.txt");
        if (!inputNumbers)
            std::cout<<"File has not been created.";
}

void FileManagement::closeOutputFile() {
    outputNumbers.close();
}

void FileManagement::write(int toWrite) {
    outputNumbers << toWrite;
}
