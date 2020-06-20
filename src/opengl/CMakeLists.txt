# Search for glfw
find_package(glfw3 3.3 REQUIRED)
# Search for glew
find_package(GLEW REQUIRED)
# Search for OpenGL
find_package(OpenGL REQUIRED)


# Add gl1 executable build from gl1.cpp
add_executable(gl1 gl1.cpp)

# Link gl1 with glfw lib
target_link_libraries(gl1 glfw)
# Link gl1 with OpenGL
target_link_libraries(gl1 OpenGL::GL)
# Link gl1 with glew
#target_link_libraries(gl1 glew)
