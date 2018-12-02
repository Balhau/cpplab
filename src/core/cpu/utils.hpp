#ifndef CORE_CPU_UTILS_H
#define CORE_CPU_UTILS_H

#include <iostream>

using namespace::std;

namespace core {
    namespace cpu {
        class Utils {
            public:
                //Lengths
                static const unsigned char INT_LEN_64   =   2;
                static const unsigned char INT_LEN_128  =   4;
                static const unsigned char INT_LEN_256  =   8;
                static const unsigned char INT_LEN_512  =   16;

                static const unsigned char LONG_LEN_64  =   1;
                static const unsigned char LONG_LEN_128  =   2;
                static const unsigned char LONG_LEN_256  =   4;
                static const unsigned char LONG_LEN_512  =   8;
                
                //Masks
                static const unsigned int MASK_32=0xFFFFFFFF;
                static const unsigned int MASK_16=0xFFFF;
                static const unsigned int MASK_8=0xFF;

                static void print(int* num,int len) {
                    for(int i=0;i<len;i++){
                        cout << num[i] ;
                        if(i<len-1){
                            cout << ",";
                        }
                    }
                    cout << endl;
                }
        };
    };
};

#endif