cmake_minimum_required(VERSION 3.10.0)
project(DatabasePractice VERSION 0.1.0 LANGUAGES C CXX)

find_package(SQLite3 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp helpers.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SQLite::SQLite3)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

find_package(Catch2 3 REQUIRED)
add_executable(tests tests/helpers_test.cpp helpers.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})

include(CTest)
enable_testing()
add_test(SystemTest, "${CMAKE_BUILD_PREFIX}/${PROJECT_NAME}", "0")

include(Catch)
catch_discover_tests(tests) # SHOULD BE ADDING TEST CASES

set(CMAKE_RUNTIME_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
