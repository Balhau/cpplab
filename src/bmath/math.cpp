#include "math.hpp"

//http://graphics.stanford.edu/~seander/bithacks.html
//https://hbfs.wordpress.com/2008/08/05/branchless-equivalents-of-simple-functions/
//access CHAR_BIT --> const with number of bits in a byte (usually 8)
#include <limits.h>
#include <iostream>

typedef union {
    struct
    {
      Int value : 31;
      Int signal : 1;
    } int_with_msb;
    Int signed_int;
  } SignedInt;

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
 * More on unions
 * https://www.geeksforgeeks.org/union-c/
 */
inline Int msb2(Int value)
{
  SignedInt sint = {.signed_int = value};
  return sint.int_with_msb.signal;
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
Int BMath::Math<Int>::min(Int a, Int b)
{
  return b + ((a - b) & msb2(a - b));
}

template <>
Int BMath::Math<Int>::max(Int a, Int b)
{
  return a + ((b - a) & ~msb2(b - a));
}
