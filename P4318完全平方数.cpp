#include<bits/stdc++.h>
using namespace std;
#define M 100100
int v[$0],mu[$0],p[$0],k;
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
long long ask(long long n){
    long long ans=0;
    for(long long i=1;i*i<=n;i++)
        ans+=mu[i]*(n/(i*i));
    return ans;
}
long long search(long long l,long long r,long long k){
    if(l==r)return l;
    long long mid=(l+r)>>1;
    long long ans=ask(mid);
    if(ans<k) return search(mid+1,r,k);
    else return search(l,mid,k);
    
}
long long t,n;
int main(){
    linearSieve_mu(100100);
    cin>>t;
    while(t--){
        cin>>n;
        printf("%lld\n",search(1,10000000000,n));
    }
}
