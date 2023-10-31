cmake_minimum_required(VERSION 3.20)
project(infra)


file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/fmt-10.0.0/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/asio-1.28.0/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/spdlog-1.12.0/include)
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
set(SPDLOG_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/spdlog-1.12.0")
target_link_libraries(${PROJECT_NAME} ${SPDLOG_LIB_PATH}/lib/win/spdlog.lib)
set(FMT_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty/fmt-10.0.0")
target_link_libraries(${PROJECT_NAME} ${FMT_LIB_PATH}/lib/win/fmt.lib)
target_compile_options(infra PRIVATE /MT)
target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})















