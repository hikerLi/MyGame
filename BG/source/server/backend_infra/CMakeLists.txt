project(backend_infra)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/mono-6.12.0.205/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/recastnavigation-1.6.0/include)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(MONO_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/mono-6.12.0.205")
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/eglib.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/libgcmonosgen.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/libmonoutils.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/mono-2.0-sgen.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/mono-2.0-dac-sgen.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/libmonoruntime-sgen.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/libs/win/libmini-sgen.lib)

set(RECASTNAVIGATION_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/recastnavigation-1.6.0")
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/Detour.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/DetourCrowd.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/DetourTileCache.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/Recast.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/DebugUtils.lib)
target_compile_options(backend_infra PRIVATE /MT)
target_link_libraries(backend_infra infra)