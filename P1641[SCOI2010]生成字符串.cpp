#include<bits/stdc++.h>
using namespace std;
#define M 2001000
#define p 20100403
int inv[M],fac[M],ifac[M];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    fac[0]=ifac[0]=inv[1]=1;
    for(int i=2;i<=2000000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=2000000;++i)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    int ans=1ll*fac[n+m]*ifac[n]%p*ifac[m]%p-1ll*fac[n+m]*ifac[n+1]%p*ifac[m-1]%p;
    printf("%d",(ans%p+p)%p);
}