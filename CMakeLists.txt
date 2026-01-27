cmake_minimum_required(VERSION 3.10.0)
project(DatabasePractice VERSION 0.1.0 LANGUAGES C CXX)

find_package(SQLite3 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)

include(CTest)
enable_testing()
set (CMAKE_RUNTIME_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")

add_test(UnitTest, "${CMAKE_BUILD_PREFIX}/${PROJECT_NAME}", "0")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
