#include<bits/stdc++.h>
using namespace std;
#define p 10007
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int fac[10100];
int a,b,k,n,m;
int main(){
    cin>>a>>b>>k>>n>>m;
    fac[0]=1;
    for(int i=1;i<=k;i++)
        fac[i]=1ll*fac[i-1]*i%p;
    cout<<1ll*qpow(a,n)*qpow(b,m)%p*fac[k]%p*qpow(fac[n],p-2)%p*qpow(fac[m],p-2)%p;
    
}
