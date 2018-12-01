#include <iostream>
#include <string>
#include <iomanip>

#include "src/core/cpu/naive.hpp"

using namespace core::cpu;

int main(int argc, char** argcv){
    int v1_128[Naive::LEN_128] = { 0x100, 0x2,0x3,0x4 };
    int v2_128[Naive::LEN_128] = { 0x10, 0x2,0x3,0x4 };

    Naive::print(v1_128,Naive::LEN_128);
    Naive::print(v2_128,Naive::LEN_128);

    Naive::sum_128_long(v1_128,v2_128);

    Naive::print(v1_128,Naive::LEN_128);
    Naive::print(v2_128,Naive::LEN_128);

}