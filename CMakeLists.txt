cmake_minimum_required(VERSION 3.22)
project(Linq)

set(CMAKE_CXX_STANDARD 20)

add_executable(Linq main.cpp
        Linq/IOperation.hpp
        Linq/Linq.hpp
        MySQL/LinqOperation.hpp
        MySQL/IOperable.hpp MySQL/LinqMySQL.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE etddb)
