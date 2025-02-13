cmake_minimum_required(VERSION 3.31)
project(ShoppingListApp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES  Item.cpp
        Item.h
        Category.h
        List.cpp
        List.h
        Account.cpp
        Account.h
        Observer.h
        Subject.h
        PrintListQty.h
        test)

add_executable(ShoppingListApp main.cpp
)

add_library(core ${SOURCE_FILES})
target_link_libraries(ShoppingListApp core)