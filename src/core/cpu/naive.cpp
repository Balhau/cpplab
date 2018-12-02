#include "naive.hpp"
#include <iostream>

void core::cpu::Naive::sum_128_long(int *a,int *b){
    long a1 = ((long)a[0] << 32) | a[1];
    long a2 = ((long)a[2] << 32) | a[3];
    long b1 = ((long)b[0] << 32) | b[1];
    long b2 = ((long)b[2] << 32) | b[3];

    a1=a1+b1;
    a2=a2+b2;

    a[0]=a1>>32;
    a[1]=a1;
    a[2]=a2>>32;
    a[3]=a2;
};