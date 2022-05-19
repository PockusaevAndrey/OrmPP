cmake_minimum_required(VERSION 3.22)
project(Linq)

set(CMAKE_CXX_STANDARD 20)

add_executable(Linq main.cpp
#        Linq/includes/Interfaces/IOperation.h
#        Linq/includes/Interfaces/IOperationSelect.h
#        Linq/includes/Interfaces/IOperationInsert.h
#        Linq/includes/Interfaces/IOperationUpdate.h
#        Linq/includes/Interfaces/IOperationDelete.h
#        Linq/includes/Linq.h
#        MySQL/includes/MySQLSelect.h
#        MySQL/src/MySQLSelect.cpp
        Test/includes/Select.h
        Test/src/Select.cpp
        Test/includes/From.h
        Test/src/From.cpp
        Test/includes/Where.h
        Test/src/Where.cpp
        Test/includes/Linq.h
        Test/interfaces/ISelect.h
        Test/interfaces/IFrom.h
        Test/interfaces/IWhere.h
        Test/interfaces/ISqlQuery.h
        Test/includes/DatabaseComponents/includes/Column.h
        Test/includes/DatabaseComponents/includes/Table.h
        Test/includes/DatabaseComponents/src/Table.cpp
        Test/includes/DatabaseComponents/src/Column.cpp
        Test/includes/InvalidColumn.h Test/TestLinq/Table.hpp Test/TestLinq/Select.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE etddb)
