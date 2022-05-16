//
// Created by serwu on 21.04.2022.
//

#ifndef MAIN_CPP_REDBLACKTREE_H
#define MAIN_CPP_REDBLACKTREE_H
#include "RBTElement.h"


class MyRedBlackTree {
private:
    int size = 0;
    RBTElement * root;
    RBTElement * guard;
public:
    MyRedBlackTree();
    void addElement(int);
    void deleteRoot();
};


#endif //MAIN_CPP_REDBLACKTREE_H
