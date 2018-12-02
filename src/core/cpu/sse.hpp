#ifndef CORE_CPU_SSE_H
#define CORE_CPU_SSE_H

#include "types.hpp"

using namespace std;
/**
 * This will define a set of functions 
 */
namespace Core {
    namespace Cpu {
        class SSE {
            public:
                static void sum_128(UInt *a,UInt *b);
                static void sum_128(ULong *a,ULong *b);
        };
    };
};

#endif