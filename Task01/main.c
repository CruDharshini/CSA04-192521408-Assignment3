#include <stdio.h>
#include <dlfcn.h>
int main(void) {
 void *h = dlopen("./libshared.so", RTLD_NOW);
 if (!h) { fprintf(stderr,"dlopen error: %s\n",dlerror()); return 1; }
 dlerror(); void (*fn)(void) = (void (*)(void))dlsym(h,"encrypt_demo");
 const char *e=dlerror(); if(e){fprintf(stderr,"dlsym error: %s\n",e);dlclose(h);return 1;}
 fn(); dlclose(h); return 0;
}
