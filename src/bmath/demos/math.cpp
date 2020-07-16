#include "../math.hpp"
#include <iostream>

using namespace BMath;

int main(void)
{
  Int a = -12;
  Float b = -12.0f;

  Int c=-3;
  Int d=4;

  std::cout << "A: " << a << ", abs(A): " << Math<Int>::abs(a) << std::endl;
  std::cout << "B: " << b << ", abs(B): " << Math<Float>::abs(b) << std::endl;
  std::cout << "MAX(C,D)=(" << c << ", " << d << "), max(C,D): " << Math<Int>::max(d,c) << std::endl;
  std::cout << "MIN(C,D)=(" << c << ", " << d << "), min(C,D): " << Math<Int>::min(c,d) << std::endl;
}
