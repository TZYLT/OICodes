#include<bits/stdc++.h>
using namespace std;
#define M 5000100
#define mod 1000000007
int v[M],mu[M],smu[M],p[M],k;
void linearSieve_mu(int n){
    mu[1]=v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i,mu[i]=-1;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0){
                mu[i*p[j]]=0;
                break;
            }
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)
        smu[i]=(smu[i-1]+mu[i])%mod;
}
int f(int n,int m){
    int ans=0;
    for(int l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=(ans+1ll*(smu[r]-smu[l-1])*(n/l)%mod*(m/l)%mod)%mod;
    }
    return ans;
}
int g[M];
int cal(int n,int m){
    int ans=0;
    for(int l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=(ans+1ll*(g[r]-g[l-1])*f(n/l,m/l)%mod)%mod;
    }
    return ans;
}

long long qpow(long long a,long long k,long long p=mod){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    int t,k;
    scanf("%d%d",&t,&k);
    linearSieve_mu(5000000);
    for(int i=1;i<=5000000;i++)
        g[i]=(g[i-1]+qpow(i,k))%mod;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",(cal(n,m)+mod)%mod);
    }

}