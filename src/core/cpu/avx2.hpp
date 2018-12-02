#ifndef AVX2_H
#define AVX2_H

using namespace std;
/**
 * This will define a set of functions 
 */
namespace Core {
    namespace Cpu {
        class avx2 {
            public:
                static int const AVX2_INT_SIZE=16;
                static void avx_sum(int* a, int* b);
                static void printAVX2Num(int* num);
        };
    };
};
#endif