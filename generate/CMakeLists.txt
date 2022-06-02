cmake_minimum_required(VERSION 3.16)
project(orm_mysql_generate)

set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} main.cpp
        )

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        etddb
        )