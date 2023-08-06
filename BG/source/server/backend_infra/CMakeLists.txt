project(backend_infra)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

target_include_directories(backend_infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(backend_infra infra)