#include "sse.hpp"
#include <iostream>

//X86 Assembly to add two 128 bit numbers in the form of packed integers 32bit
void CPU::SSE::paddw(UInt *a,UInt *b) {
    asm(
        "movdqa %0, %%xmm1\n"
        "paddw %1, %%xmm1\n"
        "movdqa %%xmm1, %0"
        : "=m"(*a)
        : "m"(*b)
    );
};


//X86 Assembly to add two 128 bit numbers in the form of packed long 64bit
void CPU::SSE::paddd(ULong *a,ULong *b) {
    asm(
        "movdqa %0, %%xmm1\n"
        "paddd %1, %%xmm1\n"
        "movdqa %%xmm1, %0"
        : "=m"(*a)
        : "m"(*b)
    );
};