//
// Created by serwu on 17.04.2022.
//

#ifndef MAIN_CPP_FILEMANAGEMENT_H
#define MAIN_CPP_FILEMANAGEMENT_H
#include <fstream>

class FileManagement {
private:
    std::fstream file;
public:
    int getLine();
    void openFile(char, std::string);
    void closeFile();
    void writeNum(double);
    void writeStr(std::string);
};


#endif //MAIN_CPP_FILEMANAGEMENT_H
