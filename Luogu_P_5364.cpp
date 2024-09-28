#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
long long st[101][101],fac[101],ifac[101],g[101],inv[101];
long long n,k;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
long long sol(void){
    long long ans=0;
    for(int i=0;i<=k;i++)
        ans=(ans+1ll*st[k][i]*fac[i]%p*g[i]%p)%p;
    return (ans+p)%p;
}
long long f(long long x){
    if(n-x+1<0)return 1;
    long long ans=1;
    for(long long i=n;i>=n-x+1;i--)
        ans=1ll*ans*i%p;
    return ans;
}
int main(){
    st[0][0]=1;ifac[0]=fac[0]=1;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=i;j++)
            st[i][j]=(1ll*st[i-1][j-1]+1ll*j*st[i-1][j]%p)%p;
    inv[1]=1;
    for(int i=2;i<=100;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;        
    for(int i=1;i<=20;i++)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    
    cin>>n>>k;
    g[0]=(qpow(2,n)-1)%p;
    long long ans=qpow(n%=p,k);
    
    for(int i=1;i<=k;i++)
        g[i]=(g[i-1]-1ll*f(i)*ifac[i]%p)%p;
    cout<<((ans+sol())%p+p)%p<<endl;
}