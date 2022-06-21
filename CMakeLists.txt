cmake_minimum_required(VERSION 3.11...3.23)

project(
  app
  VERSION 0.1
  DESCRIPTION "An example project with CMake and VTK"
  LANGUAGES C CXX
)

set(CMAKE_BUILD_TYPE Release)

message("\n" "=========================================")
message("Project: ${PROJECT_NAME} ")
message("=========================================")

# set cmake for use std c++11
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR}/external)

find_package(VTK REQUIRED)

if(VTK_FOUND)
  message(STATUS "VTK status:")
  message(STATUS "    version: ${VTK_VERSION}")
  message(STATUS "    directory: ${VTK_DIR}")
else()
  message(FATAL_ERROR "    ERROR: VTK not found")
endif()

# #############################################################################
# SOURCE CODE
# #############################################################################
set(MAIN_SOURCE "vtk.cpp")

# #############################################################################
# EXECUTABLES
# #############################################################################
add_executable(${PROJECT_NAME} ${MAIN_SOURCE})

# #############################################################################
# TARGET LIBRARIES
# #############################################################################
target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})

message("=========================================")
message("Project: ${PROJECT_NAME} COMPILED WITH CMAKE " ${CMAKE_VERSION})
message("=========================================")