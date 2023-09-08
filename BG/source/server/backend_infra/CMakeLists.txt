project(backend_infra)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/mono-7.0.10/include/mono-2.0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/recastnavigation-1.6.0/include)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})

target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(MONO_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/mono-7.0.10")
target_link_libraries(backend_infra ${MONO_LIB_PATH}/lib/win/coreclr.dll)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/lib/win/coreclr.import.lib)
target_link_libraries(backend_infra ${MONO_LIB_PATH}/lib/win/System.Private.CoreLib.dll)

set(RECASTNAVIGATION_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty/recastnavigation-1.6.0")
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/Detour.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/DetourCrowd.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/DetourTileCache.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/Recast.lib)
target_link_libraries(backend_infra ${RECASTNAVIGATION_LIB_PATH}/lib/DebugUtils.lib)
target_compile_options(backend_infra PRIVATE /MT)
target_link_libraries(backend_infra infra)