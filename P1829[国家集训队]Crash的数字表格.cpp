#include<bits/stdc++.h>
using namespace std;
#define M 10010000
#define mod 20101009
long long v[M],mu[M],smu[M],p[M],k;
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
    for(long long i=1;i<=n;i++)
        smu[i]=(smu[i-1]+1ll*mu[i]*i%mod*i%mod)%mod;
}
long long g(long long n){
    return ((1ll*n*n+n)/2ll)%mod;
}
long long f(long long n,long long m){
    long long ans=0;
    for(long long l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=(ans+1ll*(smu[r]-smu[l-1])%mod*g(n/l)%mod*g(m/l)%mod)%mod;
    }
    return ans;
}
long long sg[M];
long long cal(long long n,long long m){
    long long ans=0;
    for(long long l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=(ans+1ll*(sg[r]-sg[l-1])%mod*f(n/l,m/l)%mod)%mod;
    }
    return ans;
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    linearSieve_mu(10000000);
    for(int i=1;i<=min(n,m);i++)
        sg[i]=(sg[i-1]+1ll*i%mod)%mod;
    printf("%lld\n",(cal(n,m)+mod)%mod);
}
