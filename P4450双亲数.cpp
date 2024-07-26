#include<bits/stdc++.h>
using namespace std;
#define M 1001000
int v[M],smu[M],mu[M],p[M],k;
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
long long a,b,d,ans;
int main(){
    linearSieve_mu(1000000);
    scanf("%lld%lld%lld",&a,&b,&d);
    if(a<b)swap(a,b);
    a/=d;
    b/=d;
    for(int i=1;i<=a;i++)
        ans+=1ll*mu[i]*(a/i)*(b/i);
    printf("%lld\n",ans);
}