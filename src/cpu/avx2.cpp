#include "avx2.hpp"
#include <iostream>
#include <string>

using namespace std;

void cpu::avx2::avx_sum(int *a, int *b)
{
}

void cpu::avx2::printAVX2Num(int *num)
{
    for (int i = 0; i < avx2::AVX2_INT_SIZE; i++)
    {
        cout << i;
        if (i < avx2::AVX2_INT_SIZE - 1)
        {
            cout << ",";
        }
    }
}