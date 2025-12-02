cmake_minimum_required(VERSION 4.0)
project(Dairesel)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dairesel main.cpp
        Node.h
        CircularLinkedList.cpp
        CircularLinkedList.h)
