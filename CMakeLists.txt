cmake_minimum_required(VERSION 3.16)
project(LINQ)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
file(GLOB
        SOURCES "src/*.cpp"
        )
file(GLOB
        MYSQL "src/MySQL/*.cpp"
        )

add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${MYSQL})
target_link_libraries(${PROJECT_NAME} PRIVATE etddb)
