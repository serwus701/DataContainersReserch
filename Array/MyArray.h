//
// Created by Michał on 13.03.2022.
//

#ifndef MAIN_CPP_MYARRAY_H
#define MAIN_CPP_MYARRAY_H


class MyArray {
private:
    int size = 0;
    int *tabPointer = nullptr;
public:
    void addFront(int);

    void addRear(int);

    void addOnPos(int, int);

    void deleteFront();

    void deleteRear();

    void deleteOnPos(int);

    void swap(int, int);

    int findFirst(int);

    int getSize();

    int get(int);

    int getFromRear(int);

    void show();

    void readFromFile(std::string);

    void deleteAll();
};


#endif //MAIN_CPP_MYARRAY_H
