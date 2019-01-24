cmake_minimum_required(VERSION 3.10)
project(truefloat)

# GMP
find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARIES NAMES gmp libgmp)
find_library(GMPXX_LIBRARIES NAMES gmpxx libgmpxx)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP DEFAULT_MSG
        GMP_INCLUDE_DIR
        GMP_LIBRARIES
        GMPXX_LIBRARIES)
message("${GMP_LIBRARIES}")
include_directories(GMP_INCLUDE_DIR)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp truefloat.cpp truefloat.hpp)

add_executable(truefloat ${SOURCE_FILES})
target_link_libraries(truefloat "${GMP_LIBRARIES}" "${GMPXX_LIBRARIES}")