cmake_minimum_required(VERSION 3.26)
project(Lab_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab_2 main.cpp
        common.h
        hString.h
        hString.cpp
        singleLinkList.h
        singleLinkList.cpp
        IO.cpp
        IO.h
        linkStack.cpp
        linkStack.h
        myAlgorithm.cpp
        myAlgorithm.h
)