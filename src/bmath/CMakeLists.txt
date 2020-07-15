add_library(
  bmath SHARED
  complex.cpp
  math.cpp
)

add_executable(
  complex
  demos/complex.cpp
  complex.cpp
)

add_executable(
  math
  demos/math.cpp
  math.cpp
)