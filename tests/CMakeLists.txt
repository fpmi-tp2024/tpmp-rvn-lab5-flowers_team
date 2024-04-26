set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../SQLiteCpp)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
file(GLOB SOURCES "../src/*.cpp")
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp)
add_executable(tests tests.cpp ${SOURCES})


target_link_libraries(tests
    gtest
    gtest_main
    pthread
    SQLiteCpp
    sqlite3
    dl)
