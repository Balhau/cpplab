#pragma once
namespace CPU
{
class avx2
{
public:
    static int const AVX2_INT_SIZE = 16;
    static void avx_sum(int *a, int *b);
    static void printAVX2Num(int *num);
};
};
