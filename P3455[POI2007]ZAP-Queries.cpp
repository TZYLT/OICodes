#include<bits/stdc++.h>
using namespace std;
#define M 60060
int v[M],mu[M],smu[M],p[M],k;
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
int n,a,b,d;
int main(){
    linearSieve_mu(60000);
    scanf("%d",&n);
    while(n--){
        int ans=0;
        scanf("%d%d%d",&a,&b,&d);
        a/=d;
        b/=d;
        if(a>b)swap(a,b);
        for(int l=1,r;l<=a;l=r+1){
            r=min(a/(a/l),b/(b/l));
            ans+=(a/l)*(b/l)*(smu[r]-smu[l-1]);
        }
        printf("%d\n",ans);
    }
    
}