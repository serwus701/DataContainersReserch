#ifndef MAIN_CPP_LISTELEMENT_H
#define MAIN_CPP_LISTELEMENT_H


class ListElement {
private:
    int container;
    ListElement *next;
    ListElement *previous;


public:
    ListElement();

    int getContainer();

    int element();

    void setNext(ListElement *);

    void setPrevious(ListElement *);

    void setContainer(int);

    ListElement *getNext();

    ListElement *getPrevious();
};


#endif //MAIN_CPP_LISTELEMENT_H
