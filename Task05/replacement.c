#include <stdio.h>
#define MAXF 10
int find(const int f[],int n,int p){for(int i=0;i<n;i++)if(f[i]==p)return i;return -1;}
int fifo(const int r[],int n,int cap){int f[MAXF],u=0,next=0, faults=0;for(int i=0;i<n;i++){if(find(f,u,r[i])>=0)continue;faults++;if(u<cap)f[u++]=r[i];else{f[next]=r[i];next=(next+1)%cap;}}return faults;}
int lru(const int r[],int n,int cap){int f[MAXF],last[MAXF],u=0,faults=0;for(int i=0;i<n;i++){int k=find(f,u,r[i]);if(k>=0){last[k]=i;continue;}faults++;if(u<cap){f[u]=r[i];last[u++]=i;}else{int v=0;for(int j=1;j<cap;j++)if(last[j]<last[v])v=j;f[v]=r[i];last[v]=i;}}return faults;}
int opt(const int r[],int n,int cap){int f[MAXF],u=0, faults=0;for(int i=0;i<n;i++){if(find(f,u,r[i])>=0)continue;faults++;if(u<cap){f[u++]=r[i];continue;}int v=0,far=-1;for(int j=0;j<cap;j++){int nx=n;for(int t=i+1;t<n;t++)if(r[t]==f[j]){nx=t;break;}if(nx>far){far=nx;v=j;}}f[v]=r[i];}return faults;}
int main(void){int r[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7};int n=sizeof r/sizeof r[0];for(int f=3;f<=4;f++)printf("%d frames: FIFO %d, LRU %d, Optimal %d\n",f,fifo(r,n,f),lru(r,n,f),opt(r,n,f));int b[]={1,2,3,4,1,2,5,1,2,3,4,5};printf("Belady string, FIFO: 3 frames %d faults, 4 frames %d faults\n",fifo(b,12,3),fifo(b,12,4));return 0;}
