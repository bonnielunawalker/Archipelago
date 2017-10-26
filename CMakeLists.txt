cmake_minimum_required(VERSION 3.8)
project(Archipelago)
set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib/libSDL2.so)
set(SDL2_TTF_LIBRARY /usr/lib/libSDL2_ttf.so)

find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES "main.cpp" "entity.cpp" "game.cpp" "graphics.cpp" "point2.cpp" "textObject.cpp" include/vector2.h)

add_executable(Archipelago ${SOURCE_FILES})
target_link_libraries(Archipelago ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${FREETYPE_LIBRARIES})
target_include_directories(Archipelago PUBLIC ${PROJECT_SOURCE_DIR}/include)