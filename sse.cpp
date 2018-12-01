#include <iostream>
#include <string>
#include <iomanip>
#include <sys/time.h>

#include "src/core/cpu/naive.hpp"
#include "src/core/cpu/sse.hpp"

using namespace core::cpu;

long int gettime(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
};

#define MAX_ITER 1000*1000*100

int main(int argc, char** argcv){
    int v1_128[Naive::INT_LEN_128] = { 0x1, 0x2,0x3,0x4 };
    int v2_128[Naive::INT_LEN_128] = { 0x1, 0x2,0x3,0x4 };

    long v1_128_l[Naive::LONG_LEN_128] = { (long)0x2<<32 | 0x2, (long)0x4<<32 | 0x3 };
    long v2_128_l[Naive::LONG_LEN_128] = { (long)0x2<<32 | 0x2, (long)0x4<<32 | 0x3 };

    long int start,end;

    Naive::print(v1_128,Naive::INT_LEN_128);
    Naive::print(v2_128,Naive::INT_LEN_128);

    start = gettime();
    for(int i=0;i<MAX_ITER;i++){
        Naive::sum_128_long(v1_128,v2_128);
    }
    end = gettime();
    cout << "Naive Approach: " << end-start << endl;

    start = gettime();
    for(int i=0;i<MAX_ITER;i++){
        SSE::sum_128(v1_128,v2_128);
    }
    end = gettime();
    cout << "SSE Approach paddw: " << end-start << endl;

    start = gettime();
    for(int i=0;i<MAX_ITER;i++){
        SSE::sum_128(v1_128_l,v2_128_l);
    }
    end = gettime();
    cout << "SSE Approach paddd: " << end-start << endl;


    //Naive::print(v1_128,Naive::LEN_128);
    //Naive::print(v2_128,Naive::LEN_128);
    

}