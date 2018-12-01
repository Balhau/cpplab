#include <iostream>
#include "src/core/blist.h"
#include "src/core/bmath/bmath.h"
#include "src/core/avx2.h"
#include <string>
#include <iomanip>

using namespace core::bmath;
using namespace core::cpu;


int main(int argc, char **argv) {
    //Iteration over class
    //blist<std::string> b = blist<std::string>(std::string("Tudor"));
    //void *lol = b.current()->value;

    int a[avx2::AVX2_INT_SIZE] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF,0x10};
    int b[avx2::AVX2_INT_SIZE] = {0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF,0x10,0x11};

    avx2::printAVX2Num(a);
    avx2::printAVX2Num(b);

    avx2::avx_sum(a,b);

    BMath  bm1 = BMath();
    BMath bm2;
    u_int64_t c1 = bm1.sum(1,2);



    char* input[1024];
    std::string str=std::string();

    for(int i=0; i<1024*1024*50; i++){
      BMath* bm2=new BMath();
      c1=c1+bm2->sum(c1,i);
      delete bm2;
    }




    std::cout << "Computed stuff" << std::endl;
    std::cin >> str;



    std::cout << "Input: " << str << std::endl;

    std::cout << "Cena1: " << c1 << std::endl;

    blist<int> list = blist<int>();
    std::cout << "List size: " << list.getSize() <<std::endl;
    list.add(1);
    list.add(2);
    std::cout << "List size: " << list.getSize() << std::endl;
    std::cout << "Current value: " << list.current()->value << std::endl;
    
    int *values = list.values();
    for(int i=0;i<list.getSize();i++){
      std::cout << "Value: " << values[i] << std::endl;
    }
    
    
    //node<int> n = node<int>(2);
    
    //std::cout << "Hello node: " << ni->value << endl;
    
    /*
    std::cout << "Hello node: " << ni->value << endl;
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Hello Blist: " << "Hello" << std::endl;
    
    //Template structs
    struct node<std::string> stringNode;
    stringNode.value = std::string("Hello Master");
    
    std::cout << stringNode.value << std::endl;
    */
    
    return 0;
}
