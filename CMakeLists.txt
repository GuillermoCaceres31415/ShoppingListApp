cmake_minimum_required(VERSION 3.31)
project(ShoppingListApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShoppingListApp main.cpp
        Item.cpp
        Item.h
        Category.h
        List.cpp
        List.h)
