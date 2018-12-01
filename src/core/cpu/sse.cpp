#include "sse.hpp"
#include <iostream>

//X86 Assembly to add two 128 bit numbers in the form of packed integers 32bit
void core::cpu::SSE::sum_128(int *a,int *b) {
    asm(
        "movdqa %0, %%xmm1\n"
        "paddw %1, %%xmm1\n"
        "movdqa %%xmm1, %0"
        : "=m"(*a)
        : "m"(*b)
    );
};


//X86 Assembly to add two 128 bit numbers in the form of packed long 64bit
void core::cpu::SSE::sum_128(long *a,long *b) {
    asm(
        "movdqa %0, %%xmm1\n"
        "paddd %1, %%xmm1\n"
        "movdqa %%xmm1, %0"
        : "=m"(*a)
        : "m"(*b)
    );
}

