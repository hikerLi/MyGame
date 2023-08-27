project(game_server)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

target_include_directories(game_server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(game_server PRIVATE /MT)
target_link_libraries(game_server backend_infra)