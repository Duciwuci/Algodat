cmake_minimum_required(VERSION 3.8)
project(AlgoDat1_Fischer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.cpp Student.h CursorList.h CursorIterator.h)
add_executable(AlgoDat1_Fischer ${SOURCE_FILES})