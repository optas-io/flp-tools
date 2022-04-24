FILE(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_executable(${PROJECT_NAME}_test ${SOURCES})
set_target_properties(${PROJECT_NAME}_test PROPERTIES CXX_STANDARD 17)

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${PROJECT_NAME}_test PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Link dependencies
target_link_libraries(${PROJECT_NAME}_test PRIVATE gtest_main)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ortools::ortools)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
