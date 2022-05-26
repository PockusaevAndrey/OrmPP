cmake_minimum_required(VERSION 3.16)
project(orm_test)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(orm)
add_subdirectory(MySQL)

#[[
add_executable(${PROJECT_NAME} main.cpp
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        orm_mysql
        orm
        )
]]
