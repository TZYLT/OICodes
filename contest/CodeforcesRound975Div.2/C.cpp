#include<bits/stdc++.h>
using namespace std;
long long t,n,k;
long long a[200100];
bool check(long long x){//printf("sb");
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=((a[i]<x)?(x-a[i]):0);
    return ans<=k;
}
long long sreach(long long l,long long r){
    printf("[%lld,%lld]",l,r);fflush(stdout);
    if(l==r)return l;
    if(l+1==r){
        if(check(r))return r;
        else return l;
    }
    long long mid=(l+r)/2;
    if(!check(mid))return sreach(l,mid-1);
    else sreach(mid,r);
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i);
        long long ans=sreach(1,10000000);
        printf("%lld\n",);
        
        for(int i=1;i<=n;i++)
            a[i]=0;
    }
}