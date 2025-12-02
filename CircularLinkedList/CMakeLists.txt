cmake_minimum_required(VERSION 4.0)
project(CircularLinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(CircularLinkedList main.cpp
        CircularLinkedList.cpp
        CircularLinkedList.h)
