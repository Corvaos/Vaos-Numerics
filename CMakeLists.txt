cmake_minimum_required(VERSION 4.4)
project(VaosNumerics)

set(CMAKE_CXX_STANDARD 20)


# -------------
#    TESTING
# -------------
#add_executable(VaosNumerics
#        # -------------- DEBUG --------------
#        examples/main.cpp
#
#        # -------------- DATA TYPES --------------
#        include/vaos/numerics/Matrix.h
#        include/vaos/numerics/Transform.h
#        include/vaos/numerics/Vector3.h
#        include/vaos/numerics/Units.h
#
#        # -------------- STATISTICS --------------
#        include/vaos/numerics/Random.h
#)

# -------------------------
#    LIBRARY COMPILATION
# -------------------------
add_library(VaosNumerics INTERFACE)
add_library(VaosNumerics::VaosNumerics ALIAS VaosNumerics)



target_include_directories(VaosNumerics INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)