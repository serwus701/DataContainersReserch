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
#include "BinaryHeap/MyBinaryHeap.h"
#include "FileManagement.h"


class Interface {
private:
    static void test();//testing structures in action

    static void testArray();//testing each structure in action (each interface)

    static void testBinary();

    static void testList();

    static void testRedBlack();

    static void output(std::string, double, int, FileManagement *);//file output

    static void simulation();//counting time of each process in each function

    static void eachArrayFunction(int, int, int, FileManagement *);//simulation of each structure

    static void eachBinaryFunction(int, int, int, FileManagement *);

    static void eachListFunction(int, int, int, FileManagement *);

    static int myInput();//getting user input

public:
    static void run();

    static bool isNumber(std::string);
};


#endif //MAIN_CPP_INTERFACE_H
