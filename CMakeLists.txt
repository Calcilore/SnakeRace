cmake_minimum_required(VERSION 3.25)
project(race)

set(CMAKE_CXX_STANDARD 17)

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Project
add_executable(${PROJECT_NAME} src/Main.cpp src/Game/Snake.cpp src/Game/World.cpp src/Engine/Vec2I.cpp src/Engine/Vec2.cpp src/Engine/Util.cpp src/Engine/MainCamera.cpp)

target_link_libraries(${PROJECT_NAME} raylib)
