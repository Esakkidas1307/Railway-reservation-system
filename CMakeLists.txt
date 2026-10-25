cmake_minimum_required(VERSION 3.20)

project(RailwayReservationTests LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Start with two modules; we will add the others after inspecting their dependencies.
add_library(railway_test_core STATIC
    utils.c
    refund.c
)

target_include_directories(railway_test_core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(railway_test_core PRIVATE --coverage -O0 -g)
    target_link_options(railway_test_core PUBLIC --coverage)
endif()

enable_testing()

add_executable(railway_tests
    tests/test_utils.cpp
    tests/test_refund.cpp
)

target_link_libraries(railway_tests PRIVATE
    railway_test_core
    GTest::gtest_main
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(railway_tests PRIVATE --coverage -O0 -g)
    target_link_options(railway_tests PRIVATE --coverage)
endif()

include(GoogleTest)
gtest_discover_tests(railway_tests)
