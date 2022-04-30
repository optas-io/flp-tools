include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

include(GoogleTest)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


FILE(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *_test.cpp)

foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  set_target_properties(${TEST_NAME} PROPERTIES CXX_STANDARD 17)
  # being a cross-platform target, we enforce standards conformance on MSVC
  target_compile_options(${TEST_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
  # Link dependencies
  target_link_libraries(${TEST_NAME} PRIVATE gtest_main)
  target_link_libraries(${TEST_NAME} PRIVATE ortools::ortools)
  target_link_libraries(${TEST_NAME} PRIVATE ${PROJECT_NAME})
  
  gtest_discover_tests(${TEST_NAME})
endforeach()
