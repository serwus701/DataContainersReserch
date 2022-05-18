//
// Created by serwu on 14.04.2022.
//

#ifndef MAIN_CPP_MYBINARYHEAP_H
#define MAIN_CPP_MYBINARYHEAP_H

#include "../Array/MyArray.h"

class MyBinaryHeap {
private:
    MyArray *body = new MyArray();
    int size = 0;

    int getDepth();//returns amount of hip levels (excluding last, incomplete one)

    void heapify(int);//recurrent algorithm used for regaining heap attributes

public:
    void add(int);

    void deleteLast();

    void deleteRoot();

    void regainHeapAttributes();//structure regains heap attributes

    void show();

    int findFirst(int);//returns position of first element with equal to given value

    void deleteAll();//delete structure

    void readFromFile(std::string);//file input
};


#endif //MAIN_CPP_MYBINARYHEAP_H
