#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p=2001000;
int n,hason[p],f[p],yy=1;
int u,v;
int tot,la[p*2],to[p*2],h[p];
void hsb(int x,int y){
    to[++tot]=y,
    la[tot]=h[x],
    h[x]=tot;
}
int hsc(int x,int y){
    for(int i=h[x];i;i=la[i])
        if(to[i]!=y)
            hason[x]+=1+hsc(to[i],x);
    return hason[x];
}
void hsa(int x,int y){
    f[x]=f[y]-(hason[x]+1)+(n-hason[x]-1);
    for(int i=h[x];i;i=la[i])
        if(to[i]!=y)
            hsa(to[i],x);
}
void hsd(int x,int y,int z){
    f[1]+=z;
    for(int i=h[x];i;i=la[i])
        if(to[i]!=y)
            hsd(to[i],x,z+1);
}
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&u,&v);
        hsb(u,v),hsb(v,u);
    }
    hsc(1,0);
    for(int i=h[1];i;i=la[i])
        hsd(to[i],1,1);
    for(int i=h[1];i;i=la[i])
        hsa(to[i],1);
    for(int i=2;i<=n;i++)
        if(f[i]>f[yy])
            yy=i;
    printf("%lld\n",yy);
    return 0;
}