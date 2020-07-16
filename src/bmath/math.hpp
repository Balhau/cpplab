#pragma once

#include "../cpu/types.hpp"

namespace BMath
{
template <typename T>
class Math
{
public:
  static T abs(T value);
  static T min(T a, T b);
  static T max(T a, T b);
};
} // namespace BMath