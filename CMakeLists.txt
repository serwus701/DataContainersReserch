cmake_minimum_required(VERSION 3.19)
project(Proj1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proj1 main.cpp List/ListElement.cpp List/ListElement.h List/MyList.cpp List/MyList.h Array/MyArray.cpp Array/MyArray.h BinaryTree/MyBinaryTree.cpp BinaryTree/MyBinaryTree.h Interface.cpp Interface.h FileManagement.cpp FileManagement.h)