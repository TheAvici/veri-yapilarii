cmake_minimum_required(VERSION 4.0)
project(Stack_Queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(Stack_Queue main.cpp
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h)
