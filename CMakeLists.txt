#
#   When working on development for VaosNumerics, it utilizes a check
#   to determine if it should built a binary or library, with library
#   as the default. To switch to binary for testing, add in the
#   following to your CMake arguments during compilation:
#   -DVAOS_NUMERICS_BUILD_TESTS=ON
#

cmake_minimum_required(VERSION 4.2)
project(VaosNumerics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# Option to toggle test executable building (defaults to OFF when included via FetchContent)
option(VAOS_NUMERICS_BUILD_TESTS "Build test executable for VaosNumerics" OFF)

# -------------------------
#    LIBRARY DEFINITION
# -------------------------
add_library(VaosNumerics INTERFACE)
add_library(VaosNumerics::VaosNumerics ALIAS VaosNumerics)

target_sources(VaosNumerics INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
        include/vaos/numerics/Matrix.h
        include/vaos/numerics/Transform.h
        include/vaos/numerics/Vector3.h
        include/vaos/numerics/Units.h
        include/vaos/numerics/Random.h
)

target_include_directories(VaosNumerics INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# -------------------------
#    OPTIONAL TEST BINARY
# -------------------------
if(VAOS_NUMERICS_BUILD_TESTS)
    # Use a distinct target name for the test binary to prevent target collisions
    add_executable(VaosNumericsTest examples/main.cpp)
    target_link_libraries(VaosNumericsTest PRIVATE VaosNumerics)
endif()