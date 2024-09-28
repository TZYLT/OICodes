#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int dp[505][1055];
int ans[10050];
int opt[5050];
int pt,n;
inline int id(int x){return x+520;}
int main(){
    scanf("%d%d",&n,&pt);
    for(int i=1;i<=n;i++)
        scanf("%d",opt+i);
    pt=1ll*pt*qpow(100,p-2)%p;
    dp[0][id(0)]=1;
    for(int k=-n;k<=n;k++){
        memset(dp,0,sizeof dp);
        dp[0][id(0)]=1;
        for(int i=0;i<n;i++)
            for(int j=-n;j<=n;j++)if(j!=k){
                if(j+opt[i+1]!=k)dp[i+1][id(j+opt[i+1])]=(dp[i+1][id(j+opt[i+1])]+1ll*dp[i][id(j)]*(1-pt+p)%p)%p;
                else ans[id(k)]=(ans[id(k)]+1ll*dp[i][id(j)]*(1-pt+p)%p)%p;
                dp[i+1][id(j)]=(dp[i+1][id(j)]+1ll*dp[i][id(j)]*pt%p)%p;
                //ans[id(k)]=(ans[id(k)]+dp[i][id(j)])%p;
            }
    }
    // for(int j=-n;j<=n;j++)
    //     for(int i=0;i<=n;i++)
    //         ans[id(j)]=(1-1ll*(1-ans[id(j)])%p*(1-dp[i][id(j)])%p)%p;
    for(int j=-n;j<=n;j++)
        if(j!=0)printf("%d ",(ans[id(j)]+p)%p);
        else printf("1 ");
}