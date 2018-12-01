#include "sse.hpp"
#include <iostream>

//X86 Assembly to add two 128 bit numbers
void core::cpu::SSE::sum_128(int *a,int *b) {
    asm(
        "movdqa %0, %%xmm1\n"
        "paddw %1, %%xmm1\n"
        "movdqa %%xmm1, %0"
        : "=m"(*a)
        : "m"(*b)
    );
}