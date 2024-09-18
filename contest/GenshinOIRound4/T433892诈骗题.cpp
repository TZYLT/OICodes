#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int n,m;
int inv[500],fac[500],ifac[500];
int main(){
    scanf("%d%d",&n,&m);
    inv[1]=1;fac[0]=ifac[0]=1;
    for(int i=2;i<=495;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=495;++i)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%lld ",1ll*fac[max(n,m)]*ifac[abs(n-m)]%p);
        printf("\n");
    }
}