#include "naive.hpp"
#include "types.hpp"
#include <iostream>

void cpu::Naive::sum_128_long(UInt *a,UInt *b){
    ULong a1 = ((ULong)a[0] << 32) | a[1];
    ULong a2 = ((ULong)a[2] << 32) | a[3];
    ULong b1 = ((ULong)b[0] << 32) | b[1];
    ULong b2 = ((ULong)b[2] << 32) | b[3];

    a1=a1+b1;
    a2=a2+b2;

    a[0]=a1>>32;
    a[1]=a1;
    a[2]=a2>>32;
    a[3]=a2;
};