#include<bits/stdc++.h>
using namespace std;
#define M 5005000
#define N 5000000
unordered_map<int,long long> summu,sump;
long long smu[M],sphi[M],v[M],mu[M],p[M],phi[M],k;
void linearSieve_mu(int n){
    phi[1]=mu[1]=v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0){
                mu[i*p[j]]=0;
                phi[i*p[j]]=phi[i]*(p[j]);
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)
        smu[i]=smu[i-1]+mu[i],sphi[i]=sphi[i-1]+phi[i];

}
long long getmu(long long n){
    if(n<N)return smu[n];
    if(summu[n])return summu[n];
    long long ans=0;

    ans=1;
    for(long long l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(r-l+1)*getmu(n/l);
    }
    summu[n]=ans;
    return ans;
}
long long getphi(long long n){
    if(n<N)return sphi[n];
    if(sump[n])return sump[n];
    long long ans=1ll*n*(n+1)/2;

    for(long long l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(r-l+1)*getphi(n/l);
    }
    sump[n]=ans;
    return ans;
}
long long n,t;
int main(){
    linearSieve_mu(N);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld %lld\n",getphi(n),getmu(n));
    }
}