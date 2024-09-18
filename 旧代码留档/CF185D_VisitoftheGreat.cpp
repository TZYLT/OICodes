#include<bits/stdc++.h>
using namespace std;
long long t,k,l,r,p;

long long qpow(long long a,long long k,long long p){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}

int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&k,&l,&r,&p);
        if(p==2){
            printf("%d\n",(k&1)^1);
            continue;
        }
        long long ans,ans1,ans2;
        ans1=qpow(k,qpow(2,l,p-1),p)%p;
        if(ans1==1)ans=qpow(2,r-l+1,p);
        else{
            ans1=(ans1+p-1)%p;
            ans2=(qpow(k,qpow(2,r+1,p-1),p)-1+p)%p;
            ans=(ans2*qpow(ans1,p-2,p))%p;
        }
        if(k&1)printf("%lld\n",(ans*qpow(qpow(2,r-l,p),p-2,p)%p));
        else printf("%lld\n",ans);
    }
}