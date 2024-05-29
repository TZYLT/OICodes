#include<bits/stdc++.h>
using namespace std;
#define p 998244353
#define M 20000
int w[M],we[M],n,k;
int f[2][M];
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
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        w[i]=1ll*x*qpow(y,p-2)%p;
        we[i]=(1ll+p-w[i])%p;
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            if(j==0)f[i&1][j]=1ll*we[i]*f[!(i&1)][0]%p;
            else f[i&1][j]=(1ll*we[i]*f[!(i&1)][j]%p+1ll*w[i]*f[!(i&1)][j-1]%p)%p;
    printf("%d\n",f[n&1][k]);
}
