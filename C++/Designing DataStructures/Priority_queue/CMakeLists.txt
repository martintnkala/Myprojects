cmake_minimum_required(VERSION 3.26)
project(232_10_Lab_115)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(232_10_Lab_115
        priority_queue.h
        spy.h
        testPriorityQueue.cpp
        testPriorityQueue.h
        testSpy.h
        testVector.h
        unitTest.h
        vector.h)
