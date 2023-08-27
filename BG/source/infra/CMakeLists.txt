project(infra)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/fmt/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/asio-1.28.0/include)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
target_compile_options(infra PRIVATE /MT)
target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

