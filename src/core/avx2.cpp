#include "avx2.h"
#include <iostream>
#include <string>

using namespace core::cpu;

namespace core{
    namespace cpu{
        void avx2::naive_sum(int *a,int *b){
            for(int i=0;i<avx2::AVX2_INT_SIZE;i++){
                a[i] = a[i]+b[i];
            }
        }

        void avx2::avx_sum(int *a,int *b){

        }

        void avx2::printAVX2Num(int *num){
            for(int i=0;i<avx2::AVX2_INT_SIZE;i++){
                cout << i;
                if(i<avx2::AVX2_INT_SIZE-1){
                    cout << ",";
                }
            }
        }
    }
}