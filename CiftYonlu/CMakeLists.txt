cmake_minimum_required(VERSION 4.0)
project(CiftYonlu)

set(CMAKE_CXX_STANDARD 20)

add_executable(CiftYonlu main.cpp
        Node.h
        DoublyLinkedList.cpp
        DoublyLinkedList.h)
