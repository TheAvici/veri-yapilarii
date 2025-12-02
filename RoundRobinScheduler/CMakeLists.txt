cmake_minimum_required(VERSION 4.0)
project(RoundRobinScheduler)

set(CMAKE_CXX_STANDARD 20)

add_executable(RoundRobinScheduler main.cpp
        ProcessNode.h
        RoundRobinScheduler.cpp
        RoundRobinScheduler.h)
