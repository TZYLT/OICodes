#include<bits/stdc++.h>
using namespace std;
#define M 50050
int v[M],mo[M],smo[M],p[M],k;

void linearSieve_mu(int n){
    mo[1]=v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i,mo[i]=-1;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0){
                mo[i*p[j]]=0;
                break;
            }
            mo[i*p[j]]=-mo[i];
        }
    }
}
long long s[M];
int n,m,t;
int main(){
    scanf("%d",&t);
    linearSieve_mu(50000);

    for(int i=1;i<=50000;i++){
        smo[i]=smo[i-1]+mo[i];
        for(int l=1,r;l<=i;l=r+1){
            r=i/(i/l);
            int t=i/l;
            s[i]+=(r-l+1)*t;
        }
    }  
    while(t--){
        scanf("%d%d",&n,&m);
        if(n>m)swap(n,m);
        long long ans=0;
        
        for(int l=1,r;l<=n;l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=(smo[r]-smo[l-1])*s[n/l]*s[m/l];
        }
            
        printf("%lld\n",ans);
    }
}