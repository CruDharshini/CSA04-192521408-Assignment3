#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc,char **argv){long mb=argc>1?strtol(argv[1],NULL,10):64; if(mb<1||mb>2048){fprintf(stderr,"Use 1..2048 MB\n");return 1;}
 size_t n=(size_t)mb*1024*1024; unsigned char *p=malloc(n);if(!p){perror("malloc");return 1;}
 long page=sysconf(_SC_PAGESIZE); struct timespec a,b;clock_gettime(CLOCK_MONOTONIC,&a);
 for(size_t i=0;i<n;i+=(size_t)page)p[i]=1; clock_gettime(CLOCK_MONOTONIC,&b);
 printf("Touched %ld MB, page size %ld, elapsed %.6f s\n",mb,page,(b.tv_sec-a.tv_sec)+(b.tv_nsec-a.tv_nsec)/1e9);free(p);return 0;}
