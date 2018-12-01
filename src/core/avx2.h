#ifndef AVX2_H
#define AVX2_H

using namespace std;
/**
 * This will define a set of functions 
 */
namespace core {
    namespace cpu {
        class avx2 {
            public:
                static void inline naive_sum(int* a, int* b);
                static void inline avx_sum(int* a, int* b);
                static int const AVX2_INT_SIZE=16;
                static void printAVX2Num(int* num);
        };
    };
};
#endif