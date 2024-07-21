#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define p 1000000007
int v[M],mu[M],pi[M],k;
void linearSieve_mu(int n){
    mu[1]=v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])pi[++k]=i,mu[i]=-1;
        for(int j=1;j<=k&&i*pi[j]<=n;j++){
            v[i*pi[j]]=1;
            if(i%pi[j]==0){
                mu[i*pi[j]]=0;
                break;
            }
            mu[i*pi[j]]=-mu[i];
        }
    }
}
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int m;
int ans=1;

int main(){
    
    scanf("%d",&m);
    linearSieve_mu(m);
    for(int i=2;i<=m;i++)
        ans=(ans-1ll*mu[i]*(m/i)%p*qpow(m-(m/i),p-2)%p)%p;
    printf("%d\n",(ans%p+p)%p);
}