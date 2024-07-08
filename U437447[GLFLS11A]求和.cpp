#include<bits/stdc++.h>
using namespace std;
long long t,n,k;

long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a);
        a=(a*a);
        k>>=1;
    }
    return res;
}

bool check(long long n,long long k){
    if(n==1)return 1;
    for(int i=1;i<=k;i++)
        if(qpow(n,i)>1e10)return 0;
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        long long ans=0;
        if(k==1)
            for(long long l=1,r;l<=n;l=r+1){
                r=min(n/(n/l),n);
                ans+=(n/l)*(r-l+1);
            }
        else{
            for(long long i=1;check(i,k)&&qpow(i,k)<=n;i++){
                ans+=n/qpow(i,k);
            }
        }
        printf("%lld\n",ans%998244353);
    }
    
}