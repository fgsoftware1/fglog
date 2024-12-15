cmake_minimum_required(VERSION 3.31.2)
project(fglog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(spdlog CONFIG REQUIRED
	PATHS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}"
)
find_package(magic_enum CONFIG REQUIRED	
	PATHS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}"
)
find_package(glad CONFIG REQUIRED
	PATHS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}"
)
find_package(glfw3 CONFIG REQUIRED
	PATHS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}"
)
find_package(imgui CONFIG REQUIRED
	PATHS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}"
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE fglog_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(fglog ${fglog_SRCS})
target_precompile_headers(fglog PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/pch.hpp)
target_link_libraries(fglog PRIVATE imgui::imgui spdlog::spdlog_header_only magic_enum::magic_enum)

add_executable(fglog_test ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(fglog_test PRIVATE fglog spdlog::spdlog_header_only)