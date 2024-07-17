
#include<bits/stdc++.h>
using namespace std;
#define M 505
#define p 1000000007
long long f[M][M],n,K,pw[10010000];
inline long long qpow(long long a,long long k){
    return pw[k];
}
int main(){
    freopen("seg.in","r",stdin);
    freopen("seg.out","w",stdout);
    pw[0]=1;pw[1]=2;
    for(int i=2;i<=10000000;i++)
        pw[i]=1ll*pw[i-1]*pw[i-1]%p;
    scanf("%lld%lld",&n,&K);
    f[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<K;j++)  
            for(int k=i+1;k<=n;k++)
                f[k][j+1]=(f[k][j+1]+1ll*f[i][j]*(qpow(2,k-i)-1)%p*qpow(2,1ll*i*(k-i))%p);
    long long ans=0;
    for(int i=0;i<=n;i++)
        ans=(ans+1ll*f[i][K]*qpow(2,1ll*i*(n-i))%p)%p;
    printf("%lld",ans);
}