project(test_server)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/asio-1.28.0/include)

add_executable(${PROJECT_NAME} ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
set(ThirdParty_Path ../../..)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../Common_CmakeLists.txt)
target_include_directories(backend_infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(test_server PRIVATE /MT)
target_link_libraries(test_server backend_infra)