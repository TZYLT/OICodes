#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t;
int dp[10100];
signed main(){
    scanf("%lld%lld%lld",&n,&m,&t);
    for(int i=1;i<=n;i++){
        int v,w,d;
        scanf("%lld%lld%lld",&v,&w,&d);
        for(int j=1;j<=d;j<<=1){
            for(int k=t;k>=j*v;k--)
                dp[k]=max(dp[k],dp[k-j*v]+j*w);
            d-=j;
        }
        for(int k=t;k>=d*v;k--)
            dp[k]=max(dp[k],dp[k-d*v]+d*w);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
            for(int j=t;j>=0;j--){
                for(int k=0;k<=j;k++)
                    dp[j]=max(dp[j],dp[j-k]+(a*k*k+b*k+c));
            }
    }
    int ans=0;
    for(int i=0;i<=t;i++)
        ans=max(ans,dp[i]);
    printf("%lld\n",ans);
}