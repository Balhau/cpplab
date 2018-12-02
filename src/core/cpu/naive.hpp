#ifndef CORE_CPU_NAIVE_H
#define CORE_CPU_NAIVE_H

#include "types.hpp"

using namespace std;
/**
 * This will define a set of functions 
 */
namespace Core {
    namespace Cpu {
        class Naive {
            public:
                //Methods
                static void sum_128_long(UInt* a, UInt* b);
        };
    };
};

#endif