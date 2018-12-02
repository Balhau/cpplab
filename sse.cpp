#include <iostream>
#include <string>
#include <iomanip>
#include <sys/time.h>

#include "src/core/cpu/naive.hpp"
#include "src/core/cpu/sse.hpp"
#include "src/core/cpu/utils.hpp"

using namespace Core::Cpu;

long int gettime(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
};

#define MAX_ITER 1000*1000*100

int main(int argc, char** argcv){
    UInt v1_128[Utils::INT_LEN_128] = { 0x1, 0x2,0x3,0x4 };
    UInt v2_128[Utils::INT_LEN_128] = { 0x1, 0x2,0x3,0x4 };

    ULong v1_128_l[Utils::LONG_LEN_128];
    ULong v2_128_l[Utils::LONG_LEN_128];

    Utils::int128BitToLong(v1_128,v1_128_l);
    Utils::int128BitToLong(v2_128,v2_128_l);

    SSE::paddw(v1_128,v2_128);

    long int start,end;

    Utils::printHex(v1_128,Utils::INT_LEN_128);
    Utils::printHex(v2_128,Utils::INT_LEN_128);

    Utils::printHex(v1_128_l,Utils::LONG_LEN_128);
    Utils::printHex(v2_128_l,Utils::LONG_LEN_128);

    start = gettime();
    for(int i=0;i<MAX_ITER;i++){
        Naive::sum_128_long(v1_128,v2_128);
    }
    end = gettime();
    cout << "Naive Approach: " << end-start << endl;

    start = gettime();
    for(int i=0;i<MAX_ITER;i++){
        SSE::paddw(v1_128,v2_128);
    }
    end = gettime();
    cout << "SSE Approach paddw: " << end-start << endl;

    start = gettime();
    for(int i=0;i<MAX_ITER;i++){
        SSE::paddd(v1_128_l,v2_128_l);
    }
    end = gettime();
    cout << "SSE Approach paddd: " << end-start << endl;

    Utils::printHex(v1_128,Utils::INT_LEN_128);
    Utils::printHex(v1_128_l,Utils::LONG_LEN_128);

}