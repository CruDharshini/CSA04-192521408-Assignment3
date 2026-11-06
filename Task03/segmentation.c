#include <stdio.h>
#define N 3
int base[N]={1000,4000,8000}; int limit[N]={999,499,1999};
int main(void){int tests[][2]={{0,100},{1,400},{2,1500},{0,999},{1,500},{2,2000},{3,10},{1,-1}};
 for(unsigned i=0;i<sizeof tests/sizeof tests[0];i++){int s=tests[i][0],o=tests[i][1];
  if(s<0||s>=N||o<0||o>limit[s])printf("segment %d offset %d: segmentation fault (invalid)\n",s,o);
  else printf("segment %d offset %d -> physical %d\n",s,o,base[s]+o);
 }return 0;}
