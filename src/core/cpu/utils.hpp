#ifndef CORE_CPU_UTILS_H
#define CORE_CPU_UTILS_H

#include <iostream>
#include "types.hpp"

using namespace::std;


namespace Core {
    namespace Cpu {
        class Utils {
            public:
                //Lengths
                static const UChar INT_LEN_64   =   2;
                static const UChar INT_LEN_128  =   4;
                static const UChar INT_LEN_256  =   8;
                static const UChar INT_LEN_512  =   16;

                static const UChar LONG_LEN_64  =   1;
                static const UChar LONG_LEN_128  =   2;
                static const UChar LONG_LEN_256  =   4;
                static const UChar LONG_LEN_512  =   8;
                
                //Masks
                static const UInt MASK_32=0xFFFFFFFF;
                static const UInt MASK_16=0xFFFF;
                static const UInt MASK_8=0xFF;

                //Shifts
                static const UChar SHIFT_32 = 32;
                static const UChar SHIFT_16 = 16;
                static const UChar SHIFT_8  = 8;

                template<typename Number>
                static void print(Number *num,Int len) {
                    for(int i=0;i<len;i++){
                        cout << num[i] ;
                        if(i<len-1){
                            cout << ",";
                        }
                    }
                    cout << endl;
                };

                /**
                 * Utility method to convert a packaged 128bit int to 128bit long
                 */
                static void int128BitToLong(UInt *packedUInteger,ULong *packedULong){
                    packedULong[0] = (ULong)packedUInteger[1]<<32 | packedUInteger[0];
                    packedULong[1] = (ULong)packedUInteger[3]<<32 | packedUInteger[2];
                };

                /**
                 * Utility method to convert a packed 128bit long into a 128 int 
                 */
                static void long128BitToInt(ULong *packedULong, UInt *packedUInteger){
                    //Unpack first long
                    packedUInteger[0] = packedULong[0] && MASK_32;
                    packedUInteger[1] = packedULong[0] >> SHIFT_32;

                    //Unpack second long
                    packedUInteger[2] = packedULong[1] && MASK_32;
                    packedUInteger[3] = packedULong[1] >> SHIFT_32;
                };
        };
    };
};

#endif