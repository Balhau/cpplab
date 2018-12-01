#include <sys/times.h>
#include <unistd.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

void errExit(const char *msg){
    printf("ERROR: %s",msg);
    exit(1);
}

static void displayProcessTimes(const char *msg){
    struct tms t;
    clock_t clockTime;
    static long clockTicks = 0;

    if(msg != NULL)
        printf("%s",msg);

    if(clockTicks==0){
        clockTicks=sysconf(_SC_CLK_TCK);

        if(clockTicks==-1) errExit("sysconf");
    }

    clockTime=clock();
    if(clockTime==-1) errExit("clockTime");

    printf("clock() returns %ld clocks-per-sec (%.2f secs)\n",(long) clockTime,(double) clockTime);
};

int main(int argc,char* argv[], char* env[]){
    printf("Kie kie\n");

}