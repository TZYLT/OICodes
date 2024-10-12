#include<bits/stdc++.h>
using namespace std;
int n,a[1001000],b[1001000];
int T=1000;
int dp[2][1001000];
int main(){
    freopen("taxi.in","r",stdin);
    freopen("taxi.out","w",stdout);
    scanf("%d",&n);
    if(n<=2000)T=2*n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    memset(dp,0x7f,sizeof dp);
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=max(i-T,0);j<=T+i;j++)
            dp[i&1^1][j]=0x7f7f7f7f;
        for(int j=max(i-T,0);j<=T+i;j++){
            if(i<n)dp[i&1^1][j]=min(dp[i&1^1][j],dp[i&1][j]+1);
            if(j<n)dp[i&1][j+1]=min(dp[i&1][j+1],dp[i&1][j]+1);
            if(a[i+1]!=b[j+1]&&i<n&&j<n)dp[i&1^1][j+1]=min(dp[i&1^1][j+1],dp[i&1][j]+1);
        }
    }
    printf("%d\n",dp[n&1][n]);
}