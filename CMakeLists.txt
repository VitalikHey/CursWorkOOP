cmake_minimum_required(VERSION 3.26)
project(CursWorkOOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CursWorkOOP main.cpp
        library/saving/saving.h
        library/currency/currency.h
)
