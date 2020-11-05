
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../out/)

cmake_minimum_required(VERSION 3.13)

project(smotret-anime_api)

set(SOURCE_LIB src/smotret-anime_api.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(smotret-anime_api STATIC ${SOURCE_LIB})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

target_include_directories(smotret-anime_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(smotret-anime_api ${CURL_LIBRARIES})

