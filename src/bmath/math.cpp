#include "math.hpp"

//http://graphics.stanford.edu/~seander/bithacks.html
//access CHAR_BIT --> const with number of bits in a byte (usually 8)
#include <limits.h>
#include <iostream>

/**
 * This will get the most significant bit of the Int value. If the most significant bit is 1 then the number is 
 * 0x11111111 --> equals to -1 integer
 */
inline Int msb(Int value)
{
  return value >> (CHAR_BIT * sizeof(Int) - 1);
};

/**
 * This version of msb2 avoids the use of bitwise operators by destructuring the datastructure 
 * with the help of union and struct trickery. 
 * We basically define a new Union datatype named SInt we use the structure int_with_msb as a way to de-structure
 * the Int sint information. 
 */
inline Int msb2(Int value)
{
  typedef union {
    struct
    {
      Int v : 31;
      Int signal : 1;
    } int_with_msb;
    Int sint;
  } SInt;

  SInt sint = {.sint = value};
  return sint.sint;
};

/**
 * 
 */
template <>
Int BMath::Math<Int>::abs(Int value)
{
  return (value ^ msb2(value)) - msb2(value);
};

template <>
Float BMath::Math<Float>::abs(Float value)
{
  return value > 0 ? value : -value;
};

template <>
Int BMath::Math<Int>::max(Int a,Int b)
{
  return (a-b) & msb2(a-b);
}
