#ifndef CORE_CPU_SSE_H
#define CORE_CPU_SSE_H

using namespace std;
/**
 * This will define a set of functions 
 */
namespace core {
    namespace cpu {
        class SSE {
            public:
                static void sum_128(int *a,int *b);
        };
    };
};

#endif