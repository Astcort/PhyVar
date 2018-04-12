#==========================================
#Project options.
#==========================================
cmake_minimum_required(VERSION 2.8)

#==========================================
#Project name.
#==========================================
project(PhyVar)

#==========================================
#Building options.
#==========================================

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -fopenmp -Wno-deprecated")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g -gdwarf-2")
#==========================================
#Building mode handling.
#==========================================
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG)
    set(CMAKE_CONFIGURATION_TYPES Debug)
else()
    set(CMAKE_CONFIGURATION_TYPES Release)
endif()
message("Building mode: " ${CMAKE_BUILD_TYPE})

#==========================================
# Packages required
#==========================================

# Eigen3
if (NOT DEFINED EIGEN_INCLUDE_DIRS)
  set(EIGEN_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/external/Eigen" CACHE PATH "eigen")
include_directories(${EIGEN_INCLUDE_DIRS})
endif()

#==============================================
#Project sources : src, include
#==============================================
file(
    GLOB_RECURSE
    HEADER_FILES
    include/*.hpp
    )

file(
    GLOB_RECURSE
    SOURCE_FILES
    src/*.cpp
    )

set(EXECUTABLE_NAME main)

#==============================================
#Project executable definition
#==============================================
add_executable(${EXECUTABLE_NAME} ${HEADER_FILES} ${SOURCE_FILES})

 
