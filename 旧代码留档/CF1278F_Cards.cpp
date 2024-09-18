#include<bits/stdc++.h>
using namespace std;
#define M 5050
#define p 998244353
int st[M][M];
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res%p;
}
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    st[0][0]=1;
    for(int i=0;i<=k;i++)
        for(int j=1;j<=i;j++)
            st[i][j]=(1ll*st[i-1][j-1]+1ll*j*st[i-1][j])%p;
    int ans=0;
    for(int i=0;i<=k;i++){
        int t=1;
        for(int j=n-i+1;j<=n;j++)
            t=(1ll*t*j)%p;
        ans=(1ll*ans+(1ll*st[k][i]*t)%p*qpow(qpow(m,i),p-2)%p)%p;
    }
    printf("%d\n",ans);
}