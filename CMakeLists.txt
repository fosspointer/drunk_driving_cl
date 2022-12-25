cmake_minimum_required(VERSION 3.10)

project(drunk_driving_cl
	DESCRIPTION "Command line tool to demonstrate the impact of having different reaction times on driving"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB DEMO_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/demo/include/demo/*.hpp)
file(GLOB DEMO_IMPLEMENTATION ${CMAKE_CURRENT_SOURCE_DIR}/demo/src/*.cpp)

add_library(demo STATIC ${DEMO_HEADERS} ${DEMO_IMPLEMENTATION})
target_include_directories(demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/demo/include/)
target_compile_definitions(demo PUBLIC PROG_NAME="${PROJECT_NAME}")
target_compile_definitions(demo PUBLIC ARG0="--car-speed")
target_compile_definitions(demo PUBLIC ARG1="--reaction1")
target_compile_definitions(demo PUBLIC ARG2="--reaction2")

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

if (PLATFORM STREQUAL "Windows")
	target_compile_definitions(${PROJECT_NAME} PUBLIC PLATFORM_WINDOWS)
elseif (PLATFORM STREQUAL "Linux")
	target_compile_definitions(${PROJECT_NAME} PUBLIC PLATFORM_WINDOWS)
endif()

target_link_libraries(${PROJECT_NAME} demo)