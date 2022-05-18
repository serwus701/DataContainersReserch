//
// Created by serwu on 21.04.2022.
//

#ifndef MAIN_CPP_REDBLACKTREEELEMENT_H
#define MAIN_CPP_REDBLACKTREEELEMENT_H


class RBTElement {
private:
    char colour;
    int container;
    RBTElement * father;
    RBTElement * left;
    RBTElement * right;
public:
    RBTElement(RBTElement *, RBTElement *, RBTElement *, int, char);
    int getContainer();
    char getUncleColour();
    RBTElement * getLeft();
    RBTElement * getRight();
    void setFather(RBTElement*);
    void setLeft(RBTElement*);
    void setRight(RBTElement*);
    void setColour(char);
    void setContainer(int);
};


#endif //MAIN_CPP_REDBLACKTREEELEMENT_H
