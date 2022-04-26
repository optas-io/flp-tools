cmake_minimum_required(VERSION 3.19.6)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  flptools
  VERSION 0.0.42
  LANGUAGES CXX
)

option(BUILD_ORTOOLS "Build OR-Tools from submodule" OFF)
if (BUILD_ORTOOLS)
  set(BUILD_DEPS OFF)
  set(BUILD_EXAMPLES OFF)
  set(BUILD_SAMPLES OFF)
  set(BUILD_ZLIB ON)
  set(BUILD_absl ON)
  set(BUILD_Protobuf ON)
  set(BUILD_SCIP ON)
  set(USE_GLPK OFF)
  set(USE_COINOR OFF)
  set(BUILD_FLATZINC OFF)
  add_subdirectory(upstream/or-tools)
else()
  find_package(ortools CONFIG REQUIRED)
endif()

add_subdirectory(src)

option(BUILD_TESTS "Build the tests" ON)
if (BUILD_TESTS)
  enable_testing()
  message("Building tests")
  add_subdirectory(test)
endif()
