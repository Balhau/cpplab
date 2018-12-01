#ifndef BALHAU_CORE_BMATH
#define BALHAU_CORE_BMATH

#include <sys/types.h>
#include <iostream>

namespace core {
    namespace bmath {
        class BMath {
            public:
                BMath(){
                    //std::cout << "Constructor BMath called" << std::endl;
                }
                u_int64_t sum(u_int64_t a,u_int64_t b){
                    return a+b;
                }



                ~BMath(){
                    //std::cout<< "Destructor BMath called" << std::endl;
                }

        };
    };
}
#endif