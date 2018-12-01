#include <stdio.h>

int hijackMethod(){
    printf("This should never be called");
    printf("Neither this...");
    return 0;
}