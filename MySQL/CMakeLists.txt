cmake_minimum_required(VERSION 3.16)
project(orm_mysql)

set(CMAKE_CXX_STANDARD 20)
set(VERSION 1.0.0)
include_directories(../orm/include)

file(GLOB
        MYSQL "src/*.cpp"
        )

add_library(${PROJECT_NAME} SHARED ${MYSQL})
add_library(${PROJECT_NAME}::lib_mysql ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC orm)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${VERSION})
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION lib)
install(EXPORT ${PROJECT_NAME}Config DESTINATION cmake)
export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}Config.cmake)
set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")
