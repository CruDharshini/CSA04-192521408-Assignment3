#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
volatile unsigned long sink;
int main(void){size_t n=1024*1024;unsigned char *p=malloc(n);if(!p){perror("malloc");return 1;}if(mlock(p,n)!=0){perror("mlock (try sudo / raise RLIMIT_MEMLOCK)");free(p);return 1;}long pg=sysconf(_SC_PAGESIZE);struct timespec a,b;clock_gettime(CLOCK_MONOTONIC,&a);for(int k=0;k<100000;k++)sink+=p[(size_t)(k%(n/(size_t)pg))*(size_t)pg];clock_gettime(CLOCK_MONOTONIC,&b);printf("Locked %zu bytes; loop %.9f s; sink=%lu\n",n,(b.tv_sec-a.tv_sec)+(b.tv_nsec-a.tv_nsec)/1e9,sink);munlock(p,n);free(p);return 0;}
