#include<bits/stdc++.h>
using namespace std;
#define M 2000100
long long n;
long long ans;
long long phi[M],sp[M],p[M],v[M],k;
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
    linearSieve_phi(2000010);
    for(int i=1;i<=2000000;i++)
        sp[i]=sp[i-1]+phi[i];
    
    scanf("%lld",&n);
    ans=0;
    for(int l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        long long t=(long long)n/l;
        ans+=(long long)(sp[r]-sp[l-1])*(t+1)*t/2;
    }
    printf("%lld\n",ans);
    
    
}