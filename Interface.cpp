//
// Created by serwu on 15.04.2022.
//

#include <iostream>
#include <conio.h>
#include <ntdef.h>
#include <profileapi.h>

#include "Interface.h"

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

    int howManyRepetitions = 1000;
    int totalHowManyElements = 10000;
    int startHowManyElements = 1000;
    int jump = 1000;

    FileManagement myFileManager;


    std::cout << "insert a/l/b/r" << std::endl;
    char type;
    std::cin >> type;

    int number, position;

    for (; startHowManyElements < totalHowManyElements + 1; startHowManyElements += jump) {

        if ((howManyRepetitions > 1) && (totalHowManyElements > 1))
            for (int i = 0; i < 7; i++) {
                switch (type) {
                    case 'a':
                        eachArrayFunction(i, howManyRepetitions, startHowManyElements, &myFileManager);
                        break;
                    case 'l':
                        eachListFunction(i, howManyRepetitions, startHowManyElements, &myFileManager);
                        break;
                    case 'b':
                        eachBinaryFunction(i, howManyRepetitions, startHowManyElements, &myFileManager);
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

void
Interface::eachArrayFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    std::string name;
    int number, position;
    double totalTime = 0;

    int randNumbersVector[howManyElements];
    for (int eachElement: randNumbersVector) {
        eachElement = (rand() % 200 - 100);
    }

    (*myFileManager).openFile('o', "arrayOutput");

    for (int i = 0; i < howManyRepetitions; i++) {
        MyArray myArray;

        for (int each: randNumbersVector) {
            myArray.addRear(each);
        }

        position = rand() % (howManyElements - 1) + 1;
        number = 1;
        switch (method) {
            case 0:
                name = "ADD FRONT";
                startCounter();
                myArray.addFront(number);
                totalTime += getCounter();
                break;
            case 1:
                name = "ADD REAR";
                startCounter();
                myArray.addRear(number);
                totalTime += getCounter();
                break;
            case 2:
                name = "ADD POS";
                startCounter();
                myArray.addOnPos(position, number);
                totalTime += getCounter();
                break;
            case 3:
                name = "DELETE FRONT";
                startCounter();
                myArray.deleteFront();
                totalTime += getCounter();
                break;
            case 4:
                name = "DELETE REAR";
                startCounter();
                myArray.deleteRear();
                totalTime += getCounter();
                break;
            case 5:
                name = "DELETE ON POS";
                startCounter();
                myArray.deleteOnPos(position);
                totalTime += getCounter();
                break;
            case 6:
                name = "FIND FIRST";
                startCounter();
                myArray.findFirst(number);
                totalTime += getCounter();
                break;
        }
        myArray.deleteAll();
    }

    output(name, totalTime, howManyRepetitions, myFileManager);
    (*myFileManager).closeFile();
}

void
Interface::eachBinaryFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    std::string name;
    int number, position;
    double totalTime = 0;

    int randNumbersVector[howManyElements];
    for (int eachElement: randNumbersVector) {
        eachElement = (rand() % 200 - 100);
    }

    (*myFileManager).openFile('o', "binaryOutput");

    for (int i = 0; i < howManyRepetitions; i++) {
        MyBinaryTree myBinaryTree;

        for (int each: randNumbersVector) {
            myBinaryTree.add(each);
        }

        position = rand() % (howManyElements - 1) + 1;
        number = 1;
        switch (method) {
            case 0:
                name = "ADD";
                startCounter();
                myBinaryTree.add(number);
                totalTime += getCounter();
                break;
            case 1:
                name = "DELETE LAST";
                startCounter();
                myBinaryTree.deleteLast();
                totalTime += getCounter();
                break;
            case 2:
                name = "DELETE ROOT";
                startCounter();
                myBinaryTree.deleteRoot();
                totalTime += getCounter();
                break;
            case 3:
                name = "REGAIN HIP ATTRIBUTES";
                startCounter();
                myBinaryTree.regainHipAttributes();
                totalTime += getCounter();
                break;
            case 4:
                name = "FIND FIRST";
                startCounter();
                myBinaryTree.findFirst(number);
                totalTime += getCounter();
                break;
        }
        myBinaryTree.deleteAll();
    }

    output(name, totalTime, howManyRepetitions, myFileManager);
    (*myFileManager).closeFile();
}

void
Interface::eachListFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    std::string name;
    int number, position;
    double totalTime = 0;

    int randNumbersVector[howManyElements];
    for (int eachElement: randNumbersVector) {
        eachElement = (rand() % 200 - 100);
    }


    (*myFileManager).openFile('o', "listOutput");

    for (int i = 0; i < howManyRepetitions; i++) {
        MyList myList;

        for (int each: randNumbersVector) {
            myList.addRear(each);
        }

        position = rand() % (howManyElements - 1) + 1;
        number = 1;
        switch (method) {
            case 0:
                name = "ADD FRONT";
                startCounter();
                myList.addFront(number);
                totalTime += getCounter();
                break;
            case 1:
                name = "ADD REAR";
                startCounter();
                myList.addRear(number);
                totalTime += getCounter();
                break;
            case 2:
                name = "ADD POS";
                startCounter();
                myList.addPos(position, number);
                totalTime += getCounter();
                break;
            case 3:
                name = "DELETE FRONT";
                startCounter();
                myList.deleteFront();
                totalTime += getCounter();
                break;
            case 4:
                name = "DELETE REAR";
                startCounter();
                myList.deleteRear();
                totalTime += getCounter();
                break;
            case 5:
                name = "DELETE ON POS";
                startCounter();
                myList.deletePos(position);
                totalTime += getCounter();
                break;
            case 6:
                name = "FIND FIRST";
                startCounter();
                myList.findFirst(number);
                totalTime += getCounter();
                break;
        }
        myList.deleteAll();
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
        std::cout << "insert what to do" << std::endl;
        std::cout << "[0] add front" << std::endl;
        std::cout << "[1] add rear" << std::endl;
        std::cout << "[2] add on position" << std::endl;
        std::cout << "[3] delete front" << std::endl;
        std::cout << "[4] delete rear" << std::endl;
        std::cout << "[5] delete on position" << std::endl;
        std::cout << "[6] find first" << std::endl;
        std::cout << "[7] swap" << std::endl;
        std::cout << "[8] get" << std::endl;
        std::cout << "[9] get size" << std::endl;
        std::cout << "[e] exit" << std::endl;
        std::cin >> whatToDo;

        if ((whatToDo == "add front") || (whatToDo == "0")) {
            int number = myInput();
            if (number != NULL)
                myArray.addFront(number);
            myArray.show();
        }
        if ((whatToDo == "add front") || (whatToDo == "1")) {
            int number = myInput();
            if (number != NULL)
                myArray.addRear(number);
            myArray.show();
        }
        if ((whatToDo == "add on position") || (whatToDo == "2")) {
            int number = myInput();
            int position = myInput();
            if ((number != NULL) && (number != NULL))
                myArray.addOnPos(position, number);
            myArray.show();
        }
        if ((whatToDo == "delete front") || (whatToDo == "3")) {
            myArray.deleteFront();
            myArray.show();
        }
        if ((whatToDo == "delete rear") || (whatToDo == "4")) {
            myArray.deleteRear();
            myArray.show();
        }
        if ((whatToDo == "delete on position") || (whatToDo == "5")) {
            int position = myInput();
            if (position != NULL)
                myArray.deleteOnPos(position);
            myArray.show();
        }

        if ((whatToDo == "find first") || (whatToDo == "6")) {
            int number = myInput();
            if (number != NULL)
                myArray.findFirst(number);
            myArray.show();
        }
        if ((whatToDo == "swap") || (whatToDo == "7")) {
            int pos1 = myInput();
            int pos2 = myInput();
            if ((pos1 != NULL) && (pos2 != NULL))
                myArray.swap(pos1, pos2);
            myArray.show();
        }
        if ((whatToDo == "get") || (whatToDo == "8")) {
            int position = myInput();
            if (position != NULL)
                myArray.get(position);
            myArray.show();
        }
        if ((whatToDo == "get size") || (whatToDo == "9")) {
            std::cout << myArray.getSize() << std::endl;
            myArray.show();
        }

    } while ((whatToDo != "exit") || (whatToDo == "e"));
}

void Interface::tBinary() {

    MyBinaryTree myBinaryTree;

    std::string whatToDo;
    do {
        std::cout << "insert what to do" << std::endl;
        std::cout << "[0] add" << std::endl;
        std::cout << "[1] delete rear" << std::endl;
        std::cout << "[2] delete root" << std::endl;
        std::cout << "[3] regain hip attributes" << std::endl;
        std::cout << "[4] find first" << std::endl;
        std::cout << "[e] exit" << std::endl;
        std::cin >> whatToDo;

        if ((whatToDo == "add") || (whatToDo == "0")) {
            int number = myInput();
            if (number != NULL)
                myBinaryTree.add(number);
            myBinaryTree.show();
        }
        if ((whatToDo == "delete last") || (whatToDo == "1")) {
            myBinaryTree.deleteLast();
            myBinaryTree.show();
        }
        if ((whatToDo == "delete root") || (whatToDo == "2")) {
            myBinaryTree.deleteRoot();
            myBinaryTree.show();
        }
        if ((whatToDo == "regain hip attributes") || (whatToDo == "3")) {
            myBinaryTree.regainHipAttributes();
            myBinaryTree.show();
        }
        if ((whatToDo == "find first") || (whatToDo == "4")) {
            int number = myInput();
            if (number != NULL)
                myBinaryTree.findFirst(number);
            myBinaryTree.show();
        }

    } while ((whatToDo != "exit") || (whatToDo == "e"));
}

void Interface::tList() {
    MyList myList;

    std::string whatToDo;
    do {
        std::cout << "insert what to do" << std::endl;
        std::cout << "[0] add rear" << std::endl;
        std::cout << "[1] add front" << std::endl;
        std::cout << "[2] add on position" << std::endl;
        std::cout << "[3] delete rear" << std::endl;
        std::cout << "[4] delete front" << std::endl;
        std::cout << "[5] delete on position" << std::endl;
        std::cout << "[6] get head" << std::endl;
        std::cout << "[7] get element" << std::endl;
        std::cout << "[8] find first" << std::endl;
        std::cout << "[9] get size" << std::endl;
        std::cout << "[e] exit" << std::endl;
        std::cin >> whatToDo;

        if ((whatToDo == "add rear") || (whatToDo == "6")) {
            int number = myInput();
            if (number != NULL)
                myList.addRear(number);
            myList.show();
        }
        if ((whatToDo == "add front") || (whatToDo == "6")) {
            int number = myInput();
            if (number != NULL)
                myList.addFront(number);
            myList.show();
        }
        if ((whatToDo == "add on position") || (whatToDo == "6")) {
            int number = myInput();
            int position = myInput();
            if ((number != NULL) && (number != NULL))
                myList.addPos(position, number);
            myList.show();
        }
        if ((whatToDo == "delete rear") || (whatToDo == "6")) {
            myList.deleteRear();
            myList.show();
        }
        if ((whatToDo == "delete front") || (whatToDo == "6")) {
            myList.deleteFront();
            myList.show();
        }
        if ((whatToDo == "delete on position") || (whatToDo == "6")) {
            int position = myInput();
            if (position != NULL)
                myList.deletePos(position);
            myList.show();
        }
        if ((whatToDo == "get head") || (whatToDo == "6")) {
            std::cout << myList.getHead() << std::endl;
            myList.show();
        }
        if ((whatToDo == "get element") || (whatToDo == "6")) {
            int position = myInput();
            if (position != NULL)
                std::cout << myList.getElement(position) << std::endl;
            myList.show();
        }
        if ((whatToDo == "find first") || (whatToDo == "6")) {
            int number = myInput();
            if (number != NULL)
                std::cout << myList.findFirst(number) << std::endl;
            myList.show();
        }
        if ((whatToDo == "get size") || (whatToDo == "6")) {
            std::cout << myList.getSize() << std::endl;
            myList.show();
        }

    } while ((whatToDo != "exit") || (whatToDo == "e"));
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
    //std::cout << name << std::endl;
    //std::cout << "[average per operation: " << totalTime / howMany << " nanoseconds]" << std::endl;
    (*myFileManager).writeNum(totalTime / howMany);

}

