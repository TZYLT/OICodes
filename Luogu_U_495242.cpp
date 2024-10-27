#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int po[10010000],maxr,r[10010000];
int ans,mul;
int main(){
    int n;
    scanf("%d",&n);n++;
    for(int i=1;i<=n;i++)
        scanf("%d",r+i),maxr=max(maxr,r[i]);
    po[0]=1;
    for(int i=1;i<=maxr;i++)
        po[i]=(po[i-1]+po[i-1])%p;
    
    ans=mul=1;
    for(int i=1;i<=n;i++)
        ans=1ll*ans*po[r[i]]%p,mul=1ll*mul*(po[r[i]]+p-1)%p;
    printf("%d\n",(ans-mul+p)%p);
    
}