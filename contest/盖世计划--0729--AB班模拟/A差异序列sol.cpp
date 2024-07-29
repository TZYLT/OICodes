#include<bits/stdc++.h>
#pragma optimize("O3")
using namespace std;
#define M 101100
#define p 998244353
int n,m,ans;
int inv[M],fac[M],ifac[M];
inline int C(int x,int y){if(x<0||y<0||x-y<0)return 0;return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;}
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    //auto st=clock();
    inv[1]=1;
    for(int i=2;i<=101000;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    fac[0]=ifac[0]=1;
    for(int i=1;i<=101000;i++)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){
            int t=(m-j)<<1;
            ans=(ans+1ll*t*t%p*C(n+j-1,j)%p*C(n,i)%p*C(m-j-1,i-1)%p*C(n-i+m-j-1,m-j)%p)%p;
        }
            
    printf("%d\n",ans);
    //fprintf(stderr,"%d",clock()-st);
}