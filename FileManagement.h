//
// Created by serwu on 17.04.2022.
//

#ifndef MAIN_CPP_FILEMANAGEMENT_H
#define MAIN_CPP_FILEMANAGEMENT_H
#include <fstream>

class FileManagement {
private:
    int size = 1000;
    std::fstream inputNumbers;
    std::fstream outputNumbers;
public:
    void createInputFile();
    void createOutputFile();
    void closeInputFile();
    void closeOutputFile();
    void randNumbersToFile();
    int getLine();
    void write(int);

};


#endif //MAIN_CPP_FILEMANAGEMENT_H
