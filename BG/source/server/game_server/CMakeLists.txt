project(game_server)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")



add_executable(${PROJECT_NAME} ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
set(ThirdParty_Path ../../..)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../Common_CmakeLists.txt)
target_include_directories(backend_infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(game_server PRIVATE /MT)
target_link_libraries(game_server backend_infra)