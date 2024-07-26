#include<bits/stdc++.h>
using namespace std;
__int128 f[65][65];
unsigned long long C(int x,int y){
    if(x<0||y<0||y>x)return 0;
    return f[x][y];
}
int gw(unsigned long long n,int x){
    return (n>>x)&1;
}
long long cal(unsigned long long n,int len,int ppc){
    int pc=__builtin_popcount(n>>len);
    if(ppc<pc)return 0;
    unsigned long long ans=0;
    if(pc==0)ans+=C(len-1,ppc-pc-1);
    for(int i=min(pc,1);i<=min(len-2,64);i++)
        ans+=C(len-2,ppc-pc-1);
    for(int i=len-1;i<=min(len,64);i++)
        if(gw(n,i+1)==1)ans+=C(len-1,ppc-pc);
    for(int i=len+1;i<=64;i++)
        if(gw(n,i+1)==1&&gw(n,i-1)==0)
            ans+=C(len,ppc-pc);
    return ans;
}
unsigned long long t,l,r;

void sol(int x,int y){
    f[x][y]=1;
    for(int i=max(y+1,x-y+1);i<=x;i++)
        f[x][y]*=i;
    for(int i=1;i<=min(y,x-y);i++)
        f[x][y]/=i;
}
int main(){
    //freopen("function.in","r",stdin);
    //freopen("function.out","w",stdout);
    for(int i=0;i<=63;i++)
        for(int j=0;j<=i;j++)
            sol(i,j);
    scanf("%llu",&t);
    while(t--){
        scanf("%llu%llu",&l,&r);
        l-=1;
        unsigned long long ansl=0,ansr=0;
        for(int i=1;i<=63;i++)
            if(gw(l,i)==1){
                for(int j=1;j<=63;j++)
                    ansl+=cal(l,i,j);
            }
        for(int i=1;i<=63;i++)
            if(gw(r,i)==1)
                for(int j=1;j<=63;j++)
                    ansr+=cal(r,i,j);
        
        
        printf("%llu %llu\n",ansl,ansr);
    }
}