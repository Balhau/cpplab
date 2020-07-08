#pragma once

#include <iostream>
#include "types.hpp"

using namespace std;

namespace cpu
{
class Utils
{
public:
    template <typename Number>
    static void printHex(Number *num, Int len)
    {
        for (int i = 0; i < len; i++)
        {
            cout << hex << num[i];
            if (i < len - 1)
            {
                cout << ",";
            }
        }
        cout << std::dec << endl;
    };

    /**
                 * Utility method to convert a packaged 128bit int to 128bit long
                 */
    static void int128BitToLong(UInt *packedUInteger, ULong *packedULong)
    {
        packedULong[0] = (ULong)packedUInteger[1] << 32 | packedUInteger[0];
        packedULong[1] = (ULong)packedUInteger[3] << 32 | packedUInteger[2];
    };

    /**
                 * Utility method to convert a packed 128bit long into a 128 int 
                 */
    static void long128BitToInt(ULong *packedULong, UInt *packedUInteger)
    {
        //Unpack first long
        packedUInteger[0] = packedULong[0] & MASK_32;
        packedUInteger[1] = packedULong[0] >> SHIFT_32;

        //Unpack second long
        packedUInteger[2] = packedULong[1] & MASK_32;
        packedUInteger[3] = packedULong[1] >> SHIFT_32;
    };
};
}; // namespace Cpu