cmake_minimum_required(VERSION 3.19)
project(Proj1)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

add_executable(Proj1 main.cpp List/ListElement.cpp List/ListElement.h List/MyList.cpp List/MyList.h Array/MyArray.cpp Array/MyArray.h BinaryHeap/MyBinaryHeap.cpp BinaryHeap/MyBinaryHeap.h Interface.cpp Interface.h FileManagement.cpp FileManagement.h RBTree/MyRedBlackTree.cpp RBTree/MyRedBlackTree.h RBTree/RBTElement.cpp RBTree/RBTElement.h)