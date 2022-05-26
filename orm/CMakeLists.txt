cmake_minimum_required(VERSION 3.16)
project(orm)

set(CMAKE_CXX_STANDARD 20)
set(VERSION 1.1.0)

include_directories(include)

file(GLOB
        SOURCES "src/*.cpp"
        TEMPLATES "include/orm/template_definition/*.tpp"
        )


add_library(
        ${PROJECT_NAME} SHARED
        ${SOURCES}
        ${MYSQL}
        ${TEMPLATES}
        )

add_library(${PROJECT_NAME}::lib_base ALIAS ${PROJECT_NAME})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${VERSION})
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION lib)


install(DIRECTORY include/${PROJECT_NAME} DESTINATION include
        FILES_MATCHING
        PATTERN "*.hpp"
        PATTERN "*.tpp")

install(FILES include/${PROJECT_NAME}.hpp DESTINATION include)
install(EXPORT ${PROJECT_NAME}Config DESTINATION cmake)
export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_NAME}Config.cmake)
set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")


