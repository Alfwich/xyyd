cmake_minimum_required(VERSION 3.28)

project(xyyd)

option(SDLStatic "SDL_STATIC" "ON")
option(SDLShared "SDL_SHARED" "OFF")

add_subdirectory(xyyd)
add_subdirectory(extern EXCLUDE_FROM_ALL)