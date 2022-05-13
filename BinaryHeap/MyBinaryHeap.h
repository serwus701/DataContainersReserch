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

    int getDepth();

    void heapify(int);

public:
    void add(int);

    void deleteLast();

    void deleteRoot();

    void regainHipAttributes();

    void show();

    int findFirst(int);

    void deleteAll();

    void readFromFile(std::string);
};


#endif //MAIN_CPP_MYBINARYHEAP_H
