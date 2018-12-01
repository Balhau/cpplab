#ifndef CORE_CPU_NAIVE_H
#define CORE_CPU_NAIVE_H

using namespace std;
/**
 * This will define a set of functions 
 */
namespace core {
    namespace cpu {
        class Naive {
            private:
                static const unsigned int MASK_32=0xFFFFFFFF;
            public:
                //Attributes
                static const unsigned char INT_LEN_64   =   2;
                static const unsigned char INT_LEN_128  =   4;
                static const unsigned char INT_LEN_256  =   8;
                static const unsigned char INT_LEN_512  =   16;

                static const unsigned char LONG_LEN_64  =   1;
                static const unsigned char LONG_LEN_128  =   2;
                static const unsigned char LONG_LEN_256  =   4;
                static const unsigned char LONG_LEN_512  =   8;

                //Methods
                static void sum_128_long(int* a, int* b);
                static void print(int* num,int len);
        };
    };
};

#endif