#include<bits/stdc++.h>
using namespace std;
#define M 100100
int n,m,k;
int minx[M],maxx[M],miny[M],maxy[M];
bool v[M];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    memset(minx,0x7f,sizeof minx);
    memset(miny,0x7f,sizeof miny);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int t;
            scanf("%d",&t);
            maxx[t]=max(maxx[t],i);
            minx[t]=min(minx[t],i);
            maxy[t]=max(maxy[t],j);
            miny[t]=min(miny[t],j);
            v[t]=1;
        }
    for(int i=1;i<=k;i++)
        if(v[i]){
            int t=max(maxx[i]-minx[i],maxy[i]-miny[i])+1;
            printf("%d\n",t*t);
        }else printf("0\n");
}