#include<bits/stdc++.h>
using namespace std;
#define p 1000000007

long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
long long qpowphi(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%(p-1);
        a=(a*a)%(p-1);
        k>>=1;
    }
    return res%(p-1);
}
long long qp(long long k){
    return qpow(2,qpowphi(2,k));
}
int n,k,ans;
int inv[10001000],fac[10001000],ifac[10001000];
int C(int x,int y){return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;}
int main(){
    scanf("%d%d",&n,&k);
    fac[0]=ifac[0]=inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;i++)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    for(int i=k;i<=n;i++)
        ans=(ans+(1ll*(((i-k)&1)?-1ll:1ll)*qp(n-i)%p*C(i,k))%p*C(n,i)%p)%p;
    printf("%d\n",(ans+p)%p);
}