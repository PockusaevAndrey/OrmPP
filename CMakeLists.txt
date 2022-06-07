cmake_minimum_required(VERSION 3.16)
project(orm_test)

set(CMAKE_CXX_STANDARD 20)
#[[add_subdirectory(orm)
add_subdirectory(MySQL)]]
set(DB_IP "Put your ip")
set(DB_PORT "put your port")
set(DB_LOGIN "your login")
set(DB_PASSWORD "your password")

add_custom_command( OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/gen.txt
        COMMAND ./orm_mysql_generate ${DB_IP} ${DB_PORT} ${DB_LOGIN} ${DB_PASSWORD}
        WORKING_DIRECTORY ../
        )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/gen/Config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/Config.hpp)

include_directories(db)
include_directories(include)

add_executable(${PROJECT_NAME} main.cpp gen.txt
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        orm_mysql
        orm
        etddb
        )

