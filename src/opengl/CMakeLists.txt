# Search for glfw
find_package(glfw3 3.3 REQUIRED)
# Search for glew
find_package(glew REQUIRED)
# Search for OpenGL
find_package(OpenGL REQUIRED)
add_compile_definitions(IS_DEBUG=1)



# Add gl1 executable build from gl1.cpp, glew.c and Renderer.cpp
add_executable(
  gl1
  glew.c
  gl1.cpp
  Shader.cpp
  Renderer.cpp
  VertexBuffer.cpp
  IndexBuffer.cpp
  VertexArray.cpp
  utils.cpp
)


target_link_libraries(gl1 /usr/local/lib/libGLEW.2.2.0.dylib)
# Link gl1 with glfw lib
target_link_libraries(gl1 glfw)
# Link gl1 with glew
#target_link_libraries(gl1 glew)
# Link gl1 with OpenGL
target_link_libraries(gl1 OpenGL::GL)
