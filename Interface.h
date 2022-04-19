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


class Interface {
private:
    static void array(int, int);
    static void binary(int, int);
    static void list(int, int);
    static void redBlack();

    static void tArray();
    static void tBinary();
    static void tList();
    static void tRedBlack();

    static int myInput();
    static double countAverage(double *, int size);

    static void simulation();
    static void test();

    static void eachArrayFunction(int , int , int , int , int , int );
    static void eachBinaryFunction(int , int , int , int , int );
    static void eachListFunction(int , int , int , int , int );

public:
    static void run();

    static bool isNumber(std::string);
};


#endif //MAIN_CPP_INTERFACE_H
