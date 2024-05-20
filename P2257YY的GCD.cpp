#include<bits/stdc++.h>
using namespace std;
#define M 10001000
long long v[M],mu[M],p[M],k;
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
}
long long t,n,m,smu[M],ss[M];
int main(){
    linearSieve_mu(10000000);
    scanf("%lld",&t);
    
    for(int i=1;p[i]<=10000000&&i<=k;i++)
        for(int j=1;j*p[i]<=10000000;j++)
            smu[j*p[i]]+=mu[j];
    for(int i=1;i<=10000000;i++)
        ss[i]=ss[i-1]+smu[i];
    while(t--){
        scanf("%lld%lld",&n,&m);
        if(n>m)swap(n,m);
        long long ans=0;
        for(int l=1,r;l<=n;l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=(n/l)*(m/l)*(ss[r]-ss[l-1]);
        }
        printf("%lld\n",ans);
    }
}