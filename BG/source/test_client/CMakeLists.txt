project(test_client)

file(GLOB_RECURSE ALL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
set(ThirdParty_Path ${CMAKE_CURRENT_SOURCE_DIR}/../../thirdparty)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${ThirdParty_Path}/mono-7.0.2/include/mono-2.0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${ThirdParty_Path}/asio-1.28.0/include)

set(MONO_LIB_PATH "${ThirdParty_Path}/mono-7.0.2")

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_link_libraries(${PROJECT_NAME} ${MONO_LIB_PATH}/lib/win/coreclr.import.lib)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_FILES})
set(ThirdParty_Path ../..)
include(${CMAKE_CURRENT_SOURCE_DIR}/../Common_CmakeLists.txt)
target_include_directories(backend_infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(test_client PRIVATE /MT)
target_link_libraries(test_client backend_infra)