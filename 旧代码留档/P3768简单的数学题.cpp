// #include<bits/stdc++.h>
// using namespace std;
// #define M 5105000
// #define N 5100000
// long long mod;
// unordered_map<long long,long long> summu;
// long long smu[M],v[M],mu[M],p[M],k;
// void linearSieve_mu(long long n){
//     mu[1]=v[1]=1;
//     for(int i=2;i<=n;i++){
//         if(!v[i])p[++k]=i,mu[i]=-1;
//         for(int j=1;j<=k&&i*p[j]<=n;j++){
//             v[i*p[j]]=1;
//             if(i%p[j]==0){
//                 mu[i*p[j]]=0;
//                 break;
//             }
//             mu[i*p[j]]=-mu[i];
//         }
//     }
//     for(int i=1;i<=n;i++)
//         smu[i]=(smu[i-1]+1ll*mu[i]*i%mod*i%mod)%mod;
// }
// long long qpow(long long a,long long k){
//     long long res=1;
//     while(k){
//         if(k&1) res=(res*a)%mod;
//         a=(a*a)%mod;
//         k>>=1;
//     }
//     return res%mod;
// }
// long long g(long long n){
//     n%=mod;
//     return 1ll*(1ll*n%mod*n%mod+n%mod)%mod*qpow(2,mod-2)%mod;
// }
// long long wt(long long n){
//     n%=mod;
//     return 1ll*n*(n+1)%mod*(2ll*n+1)%mod*qpow(6,mod-2)%mod;
// }
// long long getmu(long long n){
//     if(n<N)return smu[n];
//     if(summu[n])return summu[n];
//     long long ans=0;

//     ans=1;
//     for(long long l=2,r;l<=n;l=r+1){
//         r=n/(n/l);
//         ans=(ans-1ll*(wt(r)-wt(l-1))%mod*getmu(n/l)%mod)%mod;
//     }
//     summu[n]=ans;
//     return ans;
// }

// long long f(long long n){
//     long long ans=0;
//     for(long long l=1,r;l<=n;l=r+1){
//         r=n/(n/l);
//         ans=(ans+1ll*(getmu(r)-getmu(l-1))%mod*g(n/l)%mod*g(n/l)%mod)%mod;
//     }
//     return ans;
// }
// long long sg(long long n){
//     return 1ll*g(n)*g(n)%mod;
// }
// long long cal(long long n){
//     long long ans=0;
//     for(long long l=1,r;l<=n;l=r+1){
//         r=n/(n/l);
//         ans=(ans+1ll*(sg(r)-sg(l-1))%mod*f(n/l)%mod)%mod;
//     }
//     return ans;
// }
// long long n;
// int main(){
//     scanf("%lld%lld",&mod,&n);
//     linearSieve_mu(N);
//     printf("%lld\n",(cal(n)+mod)%mod);
// }
#include<bits/stdc++.h>
using namespace std;
long long mod;
#define M 10005000
#define N 10000000
unordered_map<long long,long long> sump;
long long sphi[M],v[M],p[M],phi[M],k;
long long inv2,inv6;
void linearSieve_mu(int n){
    phi[1]=v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i,phi[i]=i-1;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0){
                phi[i*p[j]]=phi[i]*(p[j]);
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
    for(int i=1;i<=n;i++)
        sphi[i]=(sphi[i-1]+1ll*i*i%mod*phi[i]%mod)%mod;
}
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%mod;
        a=(a*a)%mod;
        k>>=1;
    }
    return res%mod;
}
long long wt(long long n){
    n%=mod;
    return ((((1ll*n*(n+1)%mod)*(2ll*n%mod+1))%mod)*inv6)%mod;
}
long long g(long long n){
    n%=mod;
    return 1ll*n*(n+1)%mod*inv2%mod;
}
long long sg(long long n){
    long long ans=g(n)%mod;
    return 1ll*ans*ans%mod;
}
long long getphi(long long n){
    if(n<N)return sphi[n];
    if(sump[n])return sump[n];
    long long ans=sg(n)%mod;

    for(long long l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans=(ans-1ll*(wt(r)-wt(l-1))%mod*getphi(n/l)%mod)%mod;
    }
    sump[n]=ans;
    return ans;
}
long long cal(long long n){
    long long ans=0;
    for(long long l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans=(ans+1ll*(getphi(r)-getphi(l-1))%mod*sg(n/l)%mod)%mod;
    }
    return ans;
}
long long n;
int main(){
    scanf("%lld%lld",&mod,&n);
    inv2=qpow(2,mod-2);
    inv6=qpow(6,mod-2);
    linearSieve_mu(N);
    printf("%lld\n",(cal(n)+mod)%mod);
}