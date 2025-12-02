cmake_minimum_required(VERSION 4.0)
project(TekYonlu)

set(CMAKE_CXX_STANDARD 20)

add_executable(TekYonlu main.cpp
        Node.h
        SinglyLinkedList.cpp
        SinglyLinkedList.h)
