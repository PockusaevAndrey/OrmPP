cmake_minimum_required(VERSION 3.22)
project(Linq)

set(CMAKE_CXX_STANDARD 20)

add_executable(Linq main.cpp
        Linq/includes/Interfaces/IOperation.h
        Linq/includes/Interfaces/IOperationSelect.h
        Linq/includes/Interfaces/IOperationInsert.h
        Linq/includes/Interfaces/IOperationUpdate.h
        Linq/includes/Interfaces/IOperationDelete.h
        Linq/includes/Linq.h
        MySQL/includes/MySQLSelect.h
        MySQL/src/MySQLSelect.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE etddb)
