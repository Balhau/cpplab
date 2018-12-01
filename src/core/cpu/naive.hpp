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
                static const unsigned char LEN_64   =   2;
                static const unsigned char LEN_128  =   4;
                static const unsigned char LEN_256  =   8;
                static const unsigned char LEN_512  =   8;

                //Methods
                static void sum_128_long(int* a, int* b);
                static void print(int* num,int len);
        };
    };
};

#endif