project(infra)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.ipp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/fmt/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/asio/include)
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})