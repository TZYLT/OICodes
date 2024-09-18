#include<bits/stdc++.h>
using namespace std;
#define p 1000000009
int n,k,a[2020],b[2020],c[2020];
int f[2020][2020],g[2020],ans;

int inv[5050],fac[5050],ifac[5050];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i); 
    k=(n+k)>>1;
    fac[0]=ifac[0]=inv[1]=1;
    for(int i=2;i<=5000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=5000;++i)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;

    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        c[i]=lower_bound(b+1,b+1+n,a[i])-b-1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=c[i];j++)
            f[i][j]=(f[i-1][j]+1ll*f[i-1][j-1]*(c[i]-j+1)%p)%p;
    
    for(int i=0;i<=n;i++) g[i]=1ll*f[n][i]*fac[n-i]%p;
    for(int i=k;i<=n;i++){
        ans=(ans+1ll*fac[i]*ifac[i-k]%p*ifac[k]%p*g[i]%p*((i-k)&1?-1:1)%p)%p;
    }
    printf("%d\n",(ans%p+p)%p);
}