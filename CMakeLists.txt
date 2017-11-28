cmake_minimum_required(VERSION 3.8)
project(algorithm)

set(CMAKE_C_STANDARD 11)

#set(SOURCE_FILES BTree/Btree.cpp BTree/Btree.h BTree/BtreeNode.cpp BTree/BtreeNode.h BTree/main.cpp)
#set(SOURCE_FILES SortTestCase100000/main.c)
#set(SOURCE_FILES Sort/Bubble/bubbleSort.cpp)
#set(SOURCE_FILES Sort/Bubble/bubbleSortRecursive.cpp)
#set(SOURCE_FILES Sort/HeapSort/HeapSort.c )
#set(SOURCE_FILES Sort/QuickSort/QuickSort.cpp )
set(SOURCE_FILES Sort/SelectionSort.cpp)
add_executable(algorithm ${SOURCE_FILES})