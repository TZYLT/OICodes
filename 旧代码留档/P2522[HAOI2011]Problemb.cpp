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
long long cal(long long a,long long b,long long d){
    long long ans=0;
    if(a<b)swap(a,b);a/=d;b/=d;
    if(a==0||b==0)return 0;
    for(int l=1,r;l<=a;l=r+1){
        if(l>b)return ans;
        r=min(a/(a/l),b/(b/l));
        ans+=1ll*(smu[r]-smu[l-1])*(a/l)*(b/l);
    }
    return ans;    
}

int main(){
    linearSieve_mu(100000);
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d,k;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("%lld\n",cal(b,d,k)-cal(d,a-1,k)-cal(b,c-1,k)+cal(a-1,c-1,k));
    }
}