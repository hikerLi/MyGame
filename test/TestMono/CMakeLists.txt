cmake_minimum_required(VERSION 3.5)
project(TestMono)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/mono-2.0)
add_executable(${PROJECT_NAME} ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

target_include_directories(TestMono PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(MONO_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(TestMono ${MONO_LIB_PATH}/lib/coreclr.import.lib)


link_directories(${MONO_LIB_PATH}/lib)


target_compile_options(TestMono PRIVATE /MT)
target_link_libraries(TestMono)