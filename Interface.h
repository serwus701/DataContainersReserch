//
// Created by serwu on 15.04.2022.
//

#ifndef MAIN_CPP_INTERFACE_H
#define MAIN_CPP_INTERFACE_H

#include <cstdio>
#include <cstring>
#include <string>
#include "List//MyList.h"
#include "Array/MyArray.h"
#include "BinaryTree/MyBinaryTree.h"
#include "FileManagement.h"


class Interface {
private:
    static void tArray();
    static void tBinary();
    static void tList();
    static void tRedBlack();

    static int myInput();
    static void output(std::string, double, int, FileManagement *);

    static void simulation();
    static void test();

    static void eachArrayFunction(int , int , int , FileManagement*);
    static void eachBinaryFunction(int , int , int , FileManagement*);
    static void eachListFunction(int , int , int , FileManagement*);

public:
    static void run();

    static bool isNumber(std::string);
};


#endif //MAIN_CPP_INTERFACE_H
