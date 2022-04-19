//
// Created by serwu on 15.04.2022.
//

#include <iostream>
#include <conio.h>
#include <ntdef.h>
#include <profileapi.h>

#include "Interface.h"
#include "FileManagement.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

void startCounter() {
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart) / 1000000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double getCounter() {
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}

void Interface::run() {

    bool exit = false;

    while (!exit) {
        std::cout << "Enter simulation or test mode? (s/t) (e for exit)" << std::endl;

        char choose;
        choose = getch();
        //choose = 's';


        switch (choose) {
            case 's':
                simulation();
                break;
            case 't':
                test();
                break;
            case 'e':
                exit = true;
        }
    }

}
void Interface::simulation() {
    char type = 'c';
    int howManyRepetitions, howManyElements;
    while (type != 'e') {
        std::cout << "insert a/l/b/r" << std::endl;
        std::cin>>type;

        std::cout << "How many repetitions" << std::endl;
        std::cin >> howManyRepetitions;
        std::cout << "How many elements" << std::endl;
        std::cin >> howManyElements;

        switch (type) {
            case 'a':
                array(howManyRepetitions, howManyElements);
                break;
            case 'l':
                list(howManyRepetitions, howManyElements);
                break;
            case 'b':
                binary(howManyRepetitions, howManyElements);
                break;
            case 'r':
                redBlack();
                break;
        }
    }
}
void Interface::test() {
    char type;
    do {
        std::cout << "insert a/l/b/r" << std::endl;
        type = getch();
        switch (type) {
            case 'a':
                tArray();
                break;
            case 'l':
                tList();
                break;
            case 'b':
                tBinary();
                break;
            case 'r':
                redBlack();
                break;
        }
    } while (type != 'e');
}


void Interface::array(int howMany, int howManyElements) {

    if (howMany != NULL) {
        if (howManyElements != NULL) {
            int number, position, pos2;

            number = 5;
            position = rand() % (howManyElements - 1) + 1;
            pos2 = rand() % (howManyElements - 1) + 1;

            if ((number != NULL) && (position != NULL) && (pos2 != NULL)) {
                if ((howMany > 1) && (howManyElements > 1))
                    for (int i = 0; i < 8; i++) {
                        eachArrayFunction(i, number, position, pos2, howMany, howManyElements);
                    }
            }
        }
    }
}
void Interface::eachArrayFunction(int method, int number, int position, int pos2, int howMany, int howManyElements) {
    std::string name;
    MyArray myArrays[howMany];
    double totalTime = 0;

    for (MyArray &eachElement: myArrays) {
        //FileManagement myFileManager;
        //myFileManager.createInputFile();
        for (int i = 0; i < howManyElements; i++) {
            //int rndNumber = myFileManager.getLine();
            eachElement.addRear(5);
            //eachElement.addRear(rndNumber);
        }
        //myFileManager.closeInputFile();
    }

    for (MyArray each: myArrays) {
        switch (method) {
            case 0:
                name = "ADD FRONT";
                startCounter();
                each.addFront(number);
                totalTime += getCounter();
                break;
            case 1:
                name = "ADD REAR";
                startCounter();
                each.addRear(number);
                totalTime += getCounter();
                break;
            case 2:
                name = "ADD POS";
                startCounter();
                each.addOnPos(position, number);
                totalTime += getCounter();
                break;
            case 3:
                name = "DELETE FRONT";
                startCounter();
                each.deleteFront();
                totalTime += getCounter();
                break;
            case 4:
                name = "DELETE REAR";
                startCounter();
                each.deleteRear();
                totalTime += getCounter();
                break;
            case 5:
                name = "DELETE ON POS";
                startCounter();
                each.deleteOnPos(position);
                totalTime += getCounter();
                break;
            case 6:
                name = "FIND FIRST";
                startCounter();
                each.findFirst(number);
                totalTime += getCounter();
                break;
        }
    }

    std::cout << name << std::endl;
    std::cout << "[average per operation: " << totalTime / howMany << " nanoseconds]" << std::endl;
}
void Interface::tArray() {
    MyArray myArray;

    std::string whatToDo;
    do {
        std::cout << "insert command what to do" << std::endl;
        std::cin >> whatToDo;

        if (whatToDo == "addFront") {
            int number = myInput();
            if (number != NULL)
                myArray.addFront(number);
            myArray.show();
        }
        if (whatToDo == "addRear") {
            int number = myInput();
            if (number != NULL)
                myArray.addRear(number);
            myArray.show();
        }
        if (whatToDo == "addOnPosition") {
            int number = myInput();
            int position = myInput();
            if ((number != NULL) && (number != NULL))
                myArray.addOnPos(position, number);
            myArray.show();
        }
        if (whatToDo == "deleteFront") {
            myArray.deleteFront();
            myArray.show();
        }
        if (whatToDo == "deleteRear") {
            myArray.deleteRear();
            myArray.show();
        }
        if (whatToDo == "deleteOnPosition") {
            int position = myInput();
            if (position != NULL)
                myArray.deleteOnPos(position);
            myArray.show();
        }

        if (whatToDo == "findFirst") {
            int number = myInput();
            if (number != NULL)
                myArray.findFirst(number);
            myArray.show();
        }
        if (whatToDo == "swap") {
            int pos1 = myInput();
            int pos2 = myInput();
            if ((pos1 != NULL) && (pos2 != NULL))
                myArray.swap(pos1, pos2);
            myArray.show();
        }
        if (whatToDo == "get") {
            int position = myInput();
            if (position != NULL)
                myArray.get(position);
            myArray.show();
        }
        if (whatToDo == "getSize") {
            std::cout << myArray.getSize() << std::endl;
            myArray.show();
        }

    } while (whatToDo != "e");
}

void Interface::binary(int howMany, int howManyElements) {

    //std::cout << "How many boards?" << std::endl;
    //int howMany = myInput();
    if (howMany != NULL) {
        MyBinaryTree myBinaryTrees[howMany];

        //std::cout << "How many elements in each board? (>1)" << std::endl;
        //int howManyElements = myInput();
        if (howManyElements != NULL) {
            int number, position;
            double totalTime;

            //std::cout << "Insert number (what to add)" << std::endl;
            //number = myInput();
            number = 5;
            //std::cout << "Insert position (where to add/delete)" << std::endl;
            //position = myInput();
            position = rand() % (howManyElements - 1) + 1;

            if ((number != NULL) && (position != NULL)) {
                if ((howMany > 1) && (howManyElements > 1))
                    for (int i = 0; i < 5; i++) {
                        eachBinaryFunction(i, number, position, howMany, howManyElements);
                    }
            }
        }
    }
}
void Interface::eachBinaryFunction(int method, int number, int position, int howMany, int howManyElements) {
    std::string name;
    MyBinaryTree myBinaryTrees[howMany];
    double totalTime = 0;
    for (MyBinaryTree &eachElement: myBinaryTrees) {
        //FileManagement myFileManager;
        //myFileManager.createInputFile();
        for (int i = 0; i < howManyElements; i++) {
            //int rndNumber = myFileManager.getLine();
            //eachElement.add(rndNumber);
            eachElement.add(5);
        }
        //myFileManager.closeInputFile();
    }

    for (MyBinaryTree element: myBinaryTrees) {
        switch (method) {
            case 0:
                name = "ADD";
                startCounter();
                element.add(number);
                totalTime += getCounter();
                break;
            case 1:
                name = "DELETE LAST";
                startCounter();
                element.deleteLast();
                totalTime += getCounter();
                break;
            case 2:
                name = "DELETE ROOT";
                startCounter();
                element.deleteRoot();
                totalTime += getCounter();
                break;
            case 3:
                name = "REGAIN HIP ATTRIBUTES";
                startCounter();
                element.regainHipAttributes();
                totalTime += getCounter();
                break;
            case 4:
                name = "FIND FIRST";
                startCounter();
                element.findFirst(number);
                totalTime += getCounter();
                break;
        }
    }

    std::cout << name << std::endl;
    std::cout << "[average per operation: " << totalTime / howMany << " nanoseconds]" << std::endl;
}
void Interface::tBinary() {

    MyBinaryTree myBinaryTree;

    std::string whatToDo;
    do {
        std::cout << "insert command what to do" << std::endl;
        std::cin >> whatToDo;

        if (whatToDo == "add") {
            int number = myInput();
            if (number != NULL)
                myBinaryTree.add(number);
            myBinaryTree.show();
        }
        if (whatToDo == "deleteLast") {
            myBinaryTree.deleteLast();
            myBinaryTree.show();
        }
        if (whatToDo == "deleteRoot") {
            if (whatToDo == "deleteLast") {
                myBinaryTree.deleteRoot();
                myBinaryTree.show();
            }
            if (whatToDo == "regainHipAttributes") {
                myBinaryTree.regainHipAttributes();
                myBinaryTree.show();
            }
            if (whatToDo == "findFirst") {
                int number = myInput();
                if (number != NULL)
                    myBinaryTree.findFirst(number);
                myBinaryTree.show();
            }
        }

    } while (whatToDo != "e");
}

void Interface::list(int howMany, int howManyElements) {
    //std::cout << "How many boards?" << std::endl;
    //int howMany = myInput();
    if (howMany != NULL) {
        MyList myLists[howMany];

        //std::cout << "How many elements in each board? (>1)" << std::endl;
        //int howManyElements = myInput();
        if (howManyElements != NULL) {
            int number, position;
            double totalTime;

            //std::cout << "Insert number (what to add)" << std::endl;
            //number = myInput();
            number = 1;
            //std::cout << "Insert position (where to add/delete)" << std::endl;
            //position = myInput();
            position = 1;

            if ((number != NULL) && (position != NULL)) {
                if ((howMany > 1) && (howManyElements > 1))
                    for (int i = 0; i < 9; i++) {
                        eachListFunction(i, number, position, howMany, howManyElements);
                    }
            }

        }
    }
}
void Interface::eachListFunction(int method, int number, int position, int howMany, int howManyElements) {
    std::string name;
    MyList myLists[howMany];
    double totalTime = 0;
    for (MyList &eachElement: myLists) {
        //FileManagement myFileManager;
        //myFileManager.createInputFile();
        for (int i = 0; i < howManyElements; i++) {
            //int rndNumber = myFileManager.getLine();
            //eachElement.addRear(rndNumber);
            eachElement.addRear(5);
        }
        //myFileManager.closeInputFile();
    }

    for (MyList element: myLists) {
        switch (method) {
            case 0:
                name = "ADD FRONT";
                startCounter();
                element.addFront(number);
                totalTime += getCounter();
                break;
            case 1:
                name = "ADD REAR";
                startCounter();
                element.addRear(number);
                totalTime += getCounter();
                break;
            case 2:
                name = "ADD POS";
                startCounter();
                element.addPos(position, number);
                totalTime += getCounter();
                break;
            case 3:
                name = "DELETE FRONT";
                startCounter();
                element.deleteFront();
                totalTime += getCounter();
                break;
            case 4:
                name = "DELETE REAR";
                startCounter();
                element.deleteRear();
                totalTime += getCounter();
                break;
            case 5:
                name = "DELETE ON POS";
                startCounter();
                element.deletePos(position);
                totalTime += getCounter();
                break;
            case 6:
                name = "FIND FIRST";
                startCounter();
                element.findFirst(number);
                totalTime += getCounter();
                break;
            case 7:
                name = "GET HEAD";
                startCounter();
                element.getHead();
                totalTime += getCounter();
                break;
            case 8:
                name = "GET";
                startCounter();
                element.getElement(position);
                totalTime += getCounter();
                break;
        }
    }

    std::cout << name << std::endl;
    std::cout << "[average per operation: " << totalTime / howMany << " nanoseconds]" << std::endl;
}
void Interface::tList() {
    MyList myList;

    std::string whatToDo;
    do {
        std::cout << "insert command what to do" << std::endl;
        std::cin >> whatToDo;

        if (whatToDo == "addRear") {
            int number = myInput();
            if (number != NULL)
                myList.addRear(number);
            myList.show();
        }
        if (whatToDo == "addFront") {
            int number = myInput();
            if (number != NULL)
                myList.addFront(number);
            myList.show();
        }
        if (whatToDo == "addPosition") {
            int number = myInput();
            int position = myInput();
            if ((number != NULL) && (number != NULL))
                myList.addPos(position, number);
            myList.show();
        }
        if (whatToDo == "deleteRear") {
            myList.deleteRear();
            myList.show();
        }
        if (whatToDo == "deleteFront") {
            myList.deleteFront();
            myList.show();
        }
        if (whatToDo == "deletePosition") {
            int position = myInput();
            if (position != NULL)
                myList.deletePos(position);
            myList.show();
        }
        if (whatToDo == "getHead") {
            std::cout << myList.getHead() << std::endl;
            myList.show();
        }
        if (whatToDo == "getElement") {
            int position = myInput();
            if (position != NULL)
                std::cout << myList.getElement(position) << std::endl;
            myList.show();
        }
        if (whatToDo == "findFirst") {
            int number = myInput();
            if (number != NULL)
                std::cout << myList.findFirst(number) << std::endl;
            myList.show();
        }
        if (whatToDo == "getSize") {
            std::cout << myList.getSize() << std::endl;
            myList.show();
        }

    } while (whatToDo != "e");
}

void Interface::redBlack() {

}
void Interface::tRedBlack() {

}

bool Interface::isNumber(std::string potentialNumber) {
    bool isDigit = true;
    for (int i = 0; i < potentialNumber.length(); i++) {
        if (!isdigit(potentialNumber[i]))
            isDigit = false;
    }
    return isDigit;
}
int Interface::myInput() {
    std::cout << "insert number" << std::endl;
    std::string number;
    std::cin >> number;

    if (isNumber(number))
        return stoi(number);
    else
        return NULL;
}

