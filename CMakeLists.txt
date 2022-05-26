cmake_minimum_required(VERSION 3.16)
project(LINQ)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
file(GLOB
        SOURCES "src/*.cpp"
        )
file(GLOB
        TEMPLATES "include/LINQ/inc/*.tpp"
        )
file(GLOB
        MYSQL "src/MySQL/*.cpp"
        )

add_executable(
        ${PROJECT_NAME}
        ${SOURCES}
        ${MYSQL}
        ${TEMPLATES}
        main.cpp
        )

target_link_libraries(${PROJECT_NAME} PRIVATE etddb)
