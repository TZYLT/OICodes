#include<bits/stdc++.h>
using namespace std;
#define M 1010
int st[M][M],c[M],a[M];
long long qpow(long long a,long long b,long long p){
    if(b<0)return 0;
    long long res=1;
    while(b){
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res%p;
}
int n,x,p,m;
int ans=0;


int main(){
    scanf("%d%d%d%d",&n,&x,&p,&m);
    for(int i=0;i<=m;i++)
        scanf("%d",a+i);
    st[0][0]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=i;j++)
            st[i][j]=(1ll*st[i-1][j-1]+1ll*j*st[i-1][j]%p)%p;
    c[0]=1;
    for(int i=1;i<=m;i++)
        c[i]=1ll*c[i-1]*(n-i+1)%p;
    for(int i=0;i<=m;i++)
        for(int j=0;j<=i;j++)
            ans=(ans+1ll*a[i]*c[j]%p*st[i][j]%p*qpow(x+1,n-j,p)%p*qpow(x,j,p)%p)%p;
    printf("%d\n",ans);
}