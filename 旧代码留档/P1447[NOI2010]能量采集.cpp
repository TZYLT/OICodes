#include<bits/stdc++.h>
using namespace std;
#define M 1001000
#define N 1000000

unordered_map<int,long long> summu;
long long smu[M],v[M],mu[M],p[M],k;
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
        smu[i]=smu[i-1]+mu[i];
}
long long getmu(long long n){
    if(n<N)return smu[n];
    if(summu[n])return summu[n];
    long long ans=0;
    ans=1;
    for(long long l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(long long)(r-l+1)*getmu(n/l);
    }
    summu[n]=ans;
    return ans;
}
long long f(long long x,long long y){
    long long ans=0;
    for(long long l=1,r;l<=min(x,y);l=r+1){
        r=min(x/(x/l),y/(y/l));
        ans+=(long long)(getmu(r)-getmu(l-1))*(x/l)*(y/l);
    }
    return ans;
}
long long cal(long long n,long long m){
    long long ans=0;
    for(long long l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans+=(long long)f(n/l,m/l)*((l+r)*(r-l+1)/2);
    }
    return ans;
}
int main(){
    linearSieve_mu(N);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long ans=cal(n,m);
    ans=ans*2-n*m;
    printf("%lld\n",ans);
    return 0;
}