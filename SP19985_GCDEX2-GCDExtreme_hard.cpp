#include<bits/stdc++.h>
using namespace std;
#define M 39000000
#define N 38200000

unordered_map<int,__int128> summu;
__int128 smu[M],v[M],mu[M],p[M],k;
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
__int128 getmu(long long n){
    if(n<N)return smu[n];
    if(summu[n])return summu[n];
    __int128 ans=0;
    ans=1;
    for(long long l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(__int128)(r-l+1)*getmu(n/l);
    }
    summu[n]=ans;
    return ans;
}
long long t,x;
__int128 f(__int128 x){
    __int128 ans=0;
    for(long long l=1,r;l<=x;l=r+1){
        r=x/(x/l);
        ans+=(__int128)(getmu(r)-getmu(l-1))*(x/l)*(x/l);
    }
    return ans;
}
__int128 cal(__int128 n){
    __int128 ans=0;
    for(long long l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans+=(__int128)f(n/l)*((l+r)*(r-l+1)/2);
    }
    return ans;
}
int main(){
    linearSieve_mu(N);
    scanf("%lld",&t);
    while(t--){
        __int128 n;
        scanf("%lld",&n);
        __int128 ans=cal(n);
        ans-=(__int128)n*(n+1)/2;
        ans/=2;
        printf("%llu\n",(unsigned long long)ans);
    }
}