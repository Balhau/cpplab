#include <iostream>
#include "../complex.hpp"

using BMath::Complex;

int main(void)
{
  std::cout << "Complex numbers " << std::endl;
  Complex c1(1,1);
  Complex c2(2,2);
  std::cout << c1 << c2 << c2-c1 << c2+c1 <<std::endl;
}