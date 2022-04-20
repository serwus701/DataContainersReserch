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

        char choose = 's';
        //choose = getch();

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

    int howManyRepetitions = 100;
    int howManyElements = 1000;
    int itHowManyElements = 100;

    FileManagement myFileManager;

    myFileManager.openFile('o', "data");
    myFileManager.randNumbersToFile(howManyElements);
    myFileManager.closeFile();


    char type = 'c';
    while (type != 'e') {
        std::cout << "insert a/l/b/r" << std::endl;
        std::cin >> type;

        if ((howManyElements != NULL) && (howManyRepetitions != NULL)) {
            int number, position;
            std::cout<<"dupsko"<<std::endl;

            for (; itHowManyElements < howManyElements; itHowManyElements += 100) {
                if ((howManyRepetitions > 1) && (howManyElements > 1))
                    for (int i = 0; i < 7; i++) {
                        switch (type) {
                            case 'a':
                                eachArrayFunction(i, howManyRepetitions, itHowManyElements, &myFileManager);
                                break;
                            case 'l':
                                std::cout<<"dupsko"<<std::endl;
                                eachListFunction(i, howManyRepetitions, itHowManyElements, &myFileManager);
                                break;
                            case 'b':
                                eachBinaryFunction(i, howManyRepetitions, itHowManyElements, &myFileManager);
                                break;
                            case 'r':
                                break;
                        }
                    }
                switch (type) {
                    case 'a':
                        myFileManager.openFile('o', "arrayOutput");
                        myFileManager.writeStr("\n");
                        myFileManager.closeFile();
                        break;
                    case 'b':
                        myFileManager.openFile('o', "binaryOutput");
                        myFileManager.writeStr("\n");
                        myFileManager.closeFile();
                        break;
                    case 'l':
                        myFileManager.openFile('o', "listOutput");
                        myFileManager.writeStr("\n");
                        myFileManager.closeFile();
                        break;
                }
            }
        }
    }
}

void
Interface::eachArrayFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    std::string name;
    int number, position;
    double totalTime = 0;

    MyArray myArrays[howManyRepetitions];

    for (MyArray &eachElement: myArrays) {

        (*myFileManager).openFile('i', "data");
        for (int i = 0; i < howManyElements; i++) {
            int rndNumber = (*myFileManager).getLine();
            eachElement.addRear(rndNumber);
        }
        (*myFileManager).closeFile();
    }

    (*myFileManager).openFile('o', "arrayOutput");

    for (MyArray each: myArrays) {
        position = rand() % (howManyElements - 1) + 1;
        number = 1;
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

    output(name, totalTime, howManyRepetitions, myFileManager);
    (*myFileManager).closeFile();
}

void
Interface::eachBinaryFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    std::string name;
    int number, position;
    double totalTime = 0;

    MyBinaryTree myBinaryTrees[howManyRepetitions];

    for (MyBinaryTree &eachElement: myBinaryTrees) {
        (*myFileManager).openFile('i', "data");
        for (int i = 0; i < howManyElements; i++) {
            int rndNumber = (*myFileManager).getLine();
            eachElement.add(rndNumber);
            eachElement.add(5);
        }
        (*myFileManager).closeFile();
    }
    (*myFileManager).openFile('o', "binaryOutput");

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

    output(name, totalTime, howManyRepetitions, myFileManager);
    (*myFileManager).closeFile();
}

void
Interface::eachListFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    std::string name;
    int number, position;
    double totalTime = 0;

    MyList myLists[howManyRepetitions];

    for (MyList &eachElement: myLists) {
        (*myFileManager).openFile('i', "data");
        for (int i = 0; i < howManyElements; i++) {
            int rndNumber = (*myFileManager).getLine();
            eachElement.addRear(rndNumber);
            eachElement.addRear(5);
        }
        (*myFileManager).closeFile();
    }
    (*myFileManager).openFile('o', "listOutput");

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
        }
    }

    output(name, totalTime, howManyRepetitions, myFileManager);
    (*myFileManager).closeFile();
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
                tRedBlack();
                break;
        }
    } while (type != 'e');
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

void Interface::output(std::string name, double totalTime, int howMany, FileManagement *myFileManager) {
    std::cout << name << std::endl;
    std::cout << "[average per operation: " << totalTime / howMany << " nanoseconds]" << std::endl;
    (*myFileManager).writeNum(totalTime / howMany);

}

