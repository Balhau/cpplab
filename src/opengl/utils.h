#pragma once
#include <iostream>

#if IS_DEBUG==1
  #define LOG(x) std::cout << x << std::endl
#else
  #define LOG(x)
#endif
