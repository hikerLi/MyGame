project(backend_infra)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
set(ThirdParty_Path ../../..)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../Common_CmakeLists.txt)

target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(backend_infra PRIVATE /MT)
target_link_libraries(backend_infra infra)