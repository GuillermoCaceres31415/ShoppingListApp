cmake_minimum_required(VERSION 3.31)

set(GOOGLETEST_VERSION 1.15.2)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp
        ItemTest.cpp
        ItemFixture.cpp
        AccountTest.cpp
        AccountFixture.cpp
        ListTest.cpp
        ListFixture.cpp
        )


# Crea eseguibili per i vari test
add_executable(runAllTests.cpp ${TEST_SOURCE_FILES})
add_executable(runItemTest ItemFixture.cpp)
add_executable(runAccountTest AccountFixture.cpp)
add_executable(runListTest ListFixture.cpp)

# Collega le librerie di GoogleTest e il core del progetto agli eseguibili
target_link_libraries(runAllTests.cpp  gtest gtest_main core)
target_link_libraries(runItemTest  gtest gtest_main core)
target_link_libraries(runAccountTest  gtest gtest_main core)
target_link_libraries(runListTest  gtest gtest_main core)
