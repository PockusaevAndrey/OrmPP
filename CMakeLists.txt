cmake_minimum_required(VERSION 3.16)
project(LINQ)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
file(GLOB
        SOURCES "src/*.cpp"
        )
file(GLOB
        HEADERS "include/*.h"
        )

add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS} include/LINQ/interface/ISelect.h include/LINQ/interface/IFrom.h include/LINQ/interface/IWhere.h include/LINQ/interface/IOrderBy.h include/LINQ/exception/InvalidColumn.hpp include/LINQ/exception/InvalidQuery.hpp src/DDL/Select.cpp src/DDL/From.cpp src/DDL/Where.cpp src/DDL/OrderBy.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE etddb)
