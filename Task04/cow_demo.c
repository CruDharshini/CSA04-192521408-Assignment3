#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/types.h>
int main(void){size_t n=16*1024*1024;long pg=sysconf(_SC_PAGESIZE);char *p=malloc(n);if(!p){perror("malloc");return 1;}for(size_t i=0;i<n;i+=(size_t)pg)p[i]=1;printf("Parent initialized %zu MB. Forking...\n",n/(1024*1024));fflush(stdout);pid_t pid=fork();if(pid<0){perror("fork");free(p);return 1;}if(pid==0){for(size_t i=0;i<n;i+=(size_t)pg)p[i]=2;struct rusage u;getrusage(RUSAGE_SELF,&u);printf("Child wrote every page; minor faults=%ld major faults=%ld\n",u.ru_minflt,u.ru_majflt);free(p);_exit(0);}waitpid(pid,NULL,0);puts("Parent pages remain unchanged (copy-on-write). ");free(p);return 0;}
