#include <iostream>
#include "src/core/blist.hpp"
#include "src/core/bmath/bmath.h"
#include "src/core/cpu/avx2.hpp"
#include <string>
#include <iomanip>

using namespace Core::bmath;
using namespace Core::Cpu;


int main(int argc, char **argv) {

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
