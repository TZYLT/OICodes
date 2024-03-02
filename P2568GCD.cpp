#include<bits/stdc++.h>
using namespace std;
#define M 10000100
long long v[M],p[M],phi[M],k,sp[M];
void linearSieve(int n){
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
int n;
long long ans;
int main(){
    linearSieve(10000000);
    for(int i=1;i<=10000000;i++)
        sp[i]=sp[i-1]+phi[i];
    scanf("%d",&n);
    for(int i=1;i<=k&&p[i]<=n;i++)
        ans+=2*sp[n/p[i]]-1;
    printf("%lld\n",ans);
}