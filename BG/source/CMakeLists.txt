cmake_minimum_required(VERSION 3.5)
project(bg)
add_subdirectory(infra)
add_subdirectory(server/backend_infra)
add_subdirectory(server/game_server)
add_subdirectory(test_client)
add_subdirectory(server/test_server)

set(PRECOMPILE_DIR "${CMAKE_SOURCE_DIR}/precompile")
#add_custom_target(precompile)
add_custom_target(precompile
                  COMMAND ${CMAKE_COMMAND} -P ${PRECOMPILE_DIR}/precompile.cmake
                  COMMENT "Running precompile.cmake..."
                  )