//
// Created by serwu on 15.04.2022.
//

#include <iostream>
#include <conio.h>
#include <ntdef.h>
#include <profileapi.h>

#include "Interface.h"
#include "BinaryHeap/MyBinaryHeap.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

void startCounter() {
    //function responsible for starting timer
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart) / 1000000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double getCounter() {
    //function responsible for stopping timer and returning time
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}

void Interface::run() {
    //starting simulation - main menu - choosing between simulation mode and test mode
    bool exit = false;

    while (!exit) {
        std::cout << "Enter simulation or test mode? (s/t) (e for exit)" << std::endl;

        char choose;
        std::cin >> choose;

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
    //menu that lets you choose data structure to simulate
    //you can also insert simulation data right below this comment
    int howManyRepetitions = 1000;
    int totalHowManyElements = 10000;
    int startHowManyElements = 1000;
    int jump = 1000;

    FileManagement myFileManager;


    std::cout << "insert a/l/b/r" << std::endl;
    char type;
    std::cin >> type;

    int number, position;
    //loop responsible for having different structure sizes

    for (; startHowManyElements < totalHowManyElements + 1; startHowManyElements += jump) {

        int howManyFunctions;
        if (type == 'b')
            howManyFunctions = 3;
        else
            howManyFunctions = 7;

        if ((howManyRepetitions > 1) && (totalHowManyElements > 1))
            //loop responsible for having different functions
            for (int i = 0; i < howManyFunctions; i++) {
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
        //writing enter after each inscription
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
    //function that contains switch case for every function
    std::string name;
    int number, position;
    double totalTime = 0;

    int randNumbersVector[howManyElements];
    for (int eachElement: randNumbersVector) {
        eachElement = (rand() % 20000 - 10000);
    }
    //creates vector with random numbers

    (*myFileManager).openFile('o', "arrayOutput");

    //loop responsible for many repetitions
    for (int i = 0; i < howManyRepetitions; i++) {
        MyArray myArray;

        for (int each: randNumbersVector) {
            myArray.addRear(each);
        }
        //filling array with numbers from vector

        position = rand() % (howManyElements - 1) + 1;
        //drawing position

        number = 1;

        //choosing function
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
        //clearing memory
    }

    output(name, totalTime, howManyRepetitions, myFileManager);
    (*myFileManager).closeFile();
}

void
Interface::eachBinaryFunction(int method, int howManyRepetitions, int howManyElements, FileManagement *myFileManager) {
    //similarly to eachArrayFunction
    std::string name;
    int number, position;
    double totalTime = 0;

    int randNumbersVector[howManyElements];
    for (int eachElement: randNumbersVector) {
        eachElement = (rand() % 20000 - 10000);
    }

    (*myFileManager).openFile('o', "binaryOutput");

    for (int i = 0; i < howManyRepetitions; i++) {
        MyBinaryHeap myBinaryTree;

        for (int each: randNumbersVector) {
            myBinaryTree.add(each);
        }
        myBinaryTree.regainHipAttributes();

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
                name = "DELETE";
                startCounter();
                myBinaryTree.deleteLast();
                totalTime += getCounter();
                break;
            case 2:
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
    //similarly to eachArrayFunction
    std::string name;
    int number, position;
    double totalTime = 0;

    int randNumbersVector[howManyElements];
    for (int eachElement: randNumbersVector) {
        eachElement = (rand() % 20000 - 10000);
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
                myList.addOnPosition(position, number);
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
    //testing menu
    //you can choose your data container here
    char type = 'c';
    while (type != 'a') {
        std::cout << "insert a/l/b/r" << std::endl;
        std::cin >> type;
        switch (type) {
            case 'a':
                testArray();
                break;
            case 'l':
                testList();
                break;
            case 'b':
                testBinary();
                break;
            case 'r':
                testRedBlack();
                break;
        }
    }
}

void Interface::testArray() {
    //function menu
    //you can choose your function here

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
        std::cout << "[s] show" << std::endl;
        std::cout << "[r] read from file" << std::endl;
        std::cout << "[e] exit" << std::endl;
        std::cin >> whatToDo;
        system("cls");
        myArray.show();

        if ((whatToDo == "add front") || (whatToDo == "0")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                myArray.addFront(number);
            myArray.show();
        }
        if ((whatToDo == "add rear") || (whatToDo == "1")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                myArray.addRear(number);
            myArray.show();
        }
        if ((whatToDo == "add on position") || (whatToDo == "2")) {
            std::cout << "Insert position" << std::endl;
            int position = myInput();
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if ((position != INT64_MAX) && (number != INT64_MAX))
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
            std::cout << "Insert position" << std::endl;
            int position = myInput();
            if (position != INT64_MAX)
                myArray.deleteOnPos(position);
            myArray.show();
        }

        if ((whatToDo == "find first") || (whatToDo == "6")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                std::cout << myArray.findFirst(number) << std::endl;
        }
        if ((whatToDo == "swap") || (whatToDo == "7")) {
            std::cout << "Insert position" << std::endl;
            int pos1 = myInput();
            std::cout << "Insert position" << std::endl;
            int pos2 = myInput();
            if ((pos1 != INT64_MAX) && (pos2 != INT64_MAX))
                myArray.swap(pos1, pos2);
            myArray.show();
        }
        if ((whatToDo == "get") || (whatToDo == "8")) {
            std::cout << "Insert position" << std::endl;
            int position = myInput();
            if (position != INT64_MAX)
                std::cout << myArray.get(position) << std::endl;
        }
        if ((whatToDo == "get size") || (whatToDo == "9")) {
            std::cout << myArray.getSize() << std::endl;
        }
        if ((whatToDo == "show") || (whatToDo == "s")) { ;
            myArray.show();
        }
        if ((whatToDo == "read from file") || (whatToDo == "r")) {
            std::cout << "Input file name (without txt)" << std::endl;
            std::string fileName;
            std::cin >> fileName;
            myArray.readFromFile(fileName);
            myArray.show();
        }

    } while ((whatToDo != "exit") && (whatToDo != "e"));
}

void Interface::testBinary() {
    //similarly to testArray

    MyBinaryHeap myBinaryTree;

    std::string whatToDo;
    do {
        std::cout << "insert what to do" << std::endl;
        std::cout << "[0] add" << std::endl;
        std::cout << "[1] delete rear" << std::endl;
        std::cout << "[2] delete root" << std::endl;
        std::cout << "[3] regain hip attributes" << std::endl;
        std::cout << "[4] find first" << std::endl;
        std::cout << "[s] show" << std::endl;
        std::cout << "[r] read from file" << std::endl;
        std::cout << "[e] exit" << std::endl;
        std::cin >> whatToDo;
        system("cls");
        myBinaryTree.show();

        if ((whatToDo == "add") || (whatToDo == "0")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX) {
                myBinaryTree.add(number);
                myBinaryTree.regainHipAttributes();
            }
            myBinaryTree.show();
        }
        if ((whatToDo == "delete last") || (whatToDo == "1")) {
            myBinaryTree.deleteLast();
            myBinaryTree.regainHipAttributes();
            myBinaryTree.show();
        }
        if ((whatToDo == "delete root") || (whatToDo == "2")) {
            myBinaryTree.deleteRoot();
            myBinaryTree.regainHipAttributes();
            myBinaryTree.show();
        }
        if ((whatToDo == "regain hip attributes") || (whatToDo == "3")) {
            myBinaryTree.regainHipAttributes();
            myBinaryTree.show();
        }
        if ((whatToDo == "find first") || (whatToDo == "4")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                std::cout << myBinaryTree.findFirst(number) << std::endl;
        }
        if ((whatToDo == "show") || (whatToDo == "s")) {
            myBinaryTree.show();
        }
        if ((whatToDo == "read from file") || (whatToDo == "r")) {
            std::cout << "Input file name (without txt)" << std::endl;
            std::string fileName;
            std::cin >> fileName;
            myBinaryTree.readFromFile(fileName);
            myBinaryTree.regainHipAttributes();
            myBinaryTree.show();
        }

    } while ((whatToDo != "exit") && (whatToDo != "e"));
}

void Interface::testList() {
    //similarly to testArray

    MyList myList;

    std::string whatToDo;
    while ((whatToDo != "exit") && (whatToDo != "e")) {
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
        std::cout << "[s] show" << std::endl;
        std::cout << "[r] read from file" << std::endl;
        std::cout << "[e] exit" << std::endl;
        std::cin >> whatToDo;
        system("cls");
        myList.show();

        if ((whatToDo == "add rear") || (whatToDo == "0")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                myList.addRear(number);
            myList.show();
        }
        if ((whatToDo == "add front") || (whatToDo == "1")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                myList.addFront(number);
            myList.show();
        }
        if ((whatToDo == "add on position") || (whatToDo == "2")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            std::cout << "Insert position" << std::endl;
            int position = myInput();
            if ((position != INT64_MAX) && (number != INT64_MAX))
                myList.addOnPosition(position, number);
            myList.show();
        }
        if ((whatToDo == "delete rear") || (whatToDo == "3")) {
            myList.deleteRear();
            myList.show();
        }
        if ((whatToDo == "delete front") || (whatToDo == "4")) {
            myList.deleteFront();
            myList.show();
        }
        if ((whatToDo == "delete on position") || (whatToDo == "5")) {
            std::cout << "Insert position" << std::endl;
            int position = myInput();
            if (position != INT64_MAX)
                myList.deletePos(position);
            myList.show();
        }
        if ((whatToDo == "get head") || (whatToDo == "6")) {
            std::cout << myList.getHead() << std::endl;
        }
        if ((whatToDo == "get element") || (whatToDo == "7")) {
            std::cout << "Insert position" << std::endl;
            int position = myInput();
            if (position != INT64_MAX)
                std::cout << myList.getContainer(position) << std::endl;
        }
        if ((whatToDo == "find first") || (whatToDo == "8")) {
            std::cout << "Insert number" << std::endl;
            int number = myInput();
            if (number != INT64_MAX)
                std::cout << myList.findFirst(number) << std::endl;
        }
        if ((whatToDo == "get size") || (whatToDo == "9")) {
            std::cout << myList.getSize() << std::endl;
        }
        if ((whatToDo == "show") || (whatToDo == "10")) {
            std::cout << myList.show() << std::endl;
            myList.show();
        }

        if ((whatToDo == "read from file") || (whatToDo == "r")) {
            std::cout << "Input file name (without txt)" << std::endl;
            std::string fileName;
            std::cin >> fileName;
            myList.readFromFile(fileName);
            myList.show();
        }

    }
}

void Interface::testRedBlack() {

}

bool Interface::isNumber(std::string potentialNumber) {
    //cheching every position of string whether it is number or not
    bool isDigit = true;
    for (int i = 0; i < potentialNumber.length(); i++) {
        if (!isdigit(potentialNumber[i]))
            isDigit = false;
    }
    return isDigit;
}

int Interface::myInput() {
    //manages input
    //returns specific value if input is not a number
    std::string number;
    std::cin >> number;

    if (isNumber(number))
        return stoi(number);
    else
        return INT64_MAX;
}

void Interface::output(std::string name, double totalTime, int howMany, FileManagement *myFileManager) {
    //writing data to a file
    (*myFileManager).writeNum(totalTime / howMany);

}

