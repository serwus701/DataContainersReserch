//
// Created by serwu on 14.04.2022.
//

#ifndef MAIN_CPP_MYBINARYHIP_H
#define MAIN_CPP_MYBINARYHIP_H

#include "../Array/MyArray.h"

class MyBinaryHip {
private:
    MyArray *myTree = new MyArray();
    int size = 0;

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


#endif //MAIN_CPP_MYBINARYHIP_H
