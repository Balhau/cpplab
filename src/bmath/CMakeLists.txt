add_library(
  bmath SHARED
  complex.cpp
)

add_executable(
  complex
  demos/complex.cpp
  complex.cpp
)