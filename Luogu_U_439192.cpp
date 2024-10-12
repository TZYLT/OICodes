#include<bits/stdc++.h>
using namespace std;
#define p 998244353
long long t,n,x;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>x;
        if(x==1){
            printf("%lld\n",n);
            continue;
        }
        x%=p;
        long long ans=0;
        for(int i=61;i>=0;i--)
            if((n>>i)&1)
                (ans+=qpow(x,i))%=p;
        printf("%lld\n",ans%p);
    }
}