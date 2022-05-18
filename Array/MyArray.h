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

    void swap(int, int);//swapping elements in two given positions

    int findFirst(int);//returns position of first element with equal to given value

    int getSize();//returns size of structure

    int get(int);//returns element at the given position

    void show();

    void readFromFile(std::string);//file input

    void deleteAll();//delete structure
};


#endif //MAIN_CPP_MYARRAY_H
