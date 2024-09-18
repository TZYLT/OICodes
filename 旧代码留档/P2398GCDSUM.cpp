#include<bits/stdc++.h>
using namespace std;
#define M 100100
long long n;
long long ans;
int phi[M],p[M],v[M],k;
void linearSieve_phi(int n){
    phi[1]=v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i]){
            p[++k]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0){
                phi[i*p[j]]=phi[i]*(p[j]);
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
}

int main(){
    linearSieve_phi(100000);
    scanf("%lld",&n);
    ans=n*(n+1)/2;
    for(int i=2;i<=n;i++){
        long long t=n/(long long)i;
        ans+=(long long)phi[i]*(t+1)*t;
    }
    printf("%lld\n",ans);
}