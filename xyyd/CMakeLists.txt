add_executable(xyyd main.c)
target_include_directories(xyyd PRIVATE ${CMAKE_SOURCE_DIR}/extern/SDL/include)
target_link_libraries(xyyd PRIVATE SDL3::SDL3)