#include <iostream>
#include "src/core/blist.hpp"
#include "src/core/cpu/avx2.hpp"
#include <string>
#include <iomanip>

using namespace Core::Cpu;


int main(int argc, char **argv) {


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
