cmake_minimum_required(VERSION 4.0)
project(BrowserHistory)

set(CMAKE_CXX_STANDARD 20)

add_executable(BrowserHistory main.cpp
        Page.h
        Node.h
        BrowserHistory.cpp
        BrowserHistory.h)
