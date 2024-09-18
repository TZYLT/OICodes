#include<bits/stdc++.h>
using namespace std;
long long f[100100];
long long c[5];
long long n;
long long d[5],s;
long long t(long long i){return (d[i]+1)*c[i];}
int main(){
    scanf("%lld%lld%lld%lld%lld",&c[1],&c[2],&c[3],&c[4],&n);
    f[0]=1;
    for(int i=1;i<=4;i++)
        for(int j=c[i];j<=100000;j++)
            f[j]+=f[j-c[i]];
    
    while(n--){
        scanf("%lld%lld%lld%lld%lld",&d[1],&d[2],&d[3],&d[4],&s);
        long long ans=f[s];
        if(s-t(1)-t(2)-t(3)-t(4)>=0)ans-=f[s-t(1)-t(2)-t(3)-t(3)];
        if(s-t(1)-t(2)-t(3)>=0)ans-=f[s-t(1)-t(2)-t(3)];
        if(s-t(1)-t(2)-t(4)>=0)ans-=f[s-t(1)-t(2)-t(4)];
        if(s-t(1)-t(4)-t(3)>=0)ans-=f[s-t(1)-t(4)-t(3)];
        if(s-t(4)-t(2)-t(3)>=0)ans-=f[s-t(4)-t(2)-t(3)];
        if(s-t(1)-t(2)>=0)ans+=f[s-t(1)-t(2)];
        if(s-t(1)-t(3)>=0)ans+=f[s-t(1)-t(3)];
        if(s-t(1)-t(4)>=0)ans+=f[s-t(1)-t(4)];
        if(s-t(3)-t(2)>=0)ans+=f[s-t(3)-t(2)];
        if(s-t(4)-t(2)>=0)ans+=f[s-t(4)-t(2)];
        if(s-t(3)-t(4)>=0)ans+=f[s-t(3)-t(4)];
        if(s-t(1)>=0)ans-=f[s-t(1)];
        if(s-t(2)>=0)ans-=f[s-t(2)];
        if(s-t(3)>=0)ans-=f[s-t(3)];
        if(s-t(4)>=0)ans-=f[s-t(4)];
        printf("%lld\n",ans);
    }
}