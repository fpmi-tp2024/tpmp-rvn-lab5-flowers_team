set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/SQLiteCpp)

file(GLOB SOURCES src/*.cpp)
add_executable(bin/main ${SOURCES})


target_link_libraries(bin/main
  SQLiteCpp
  sqlite3
  pthread
  dl
  )
