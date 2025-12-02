cmake_minimum_required(VERSION 4.0)
project(CircularPlayList)

set(CMAKE_CXX_STANDARD 20)

add_executable(CircularPlayList main.cpp
        Song.h
        SingularPlaylist.cpp
        CircularPlaylist.h)
