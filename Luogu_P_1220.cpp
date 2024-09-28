#include<bits/stdc++.h>
using namespace std;
long long dp[55][55][2];
int a[55],w[55],sum[55];
int n,c;
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d%d",a+i,w+i);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+w[i];
    memset(dp,0x7f,sizeof dp);
    dp[c][c][0]=dp[c][c][1]=0;
    for(int len=2;len<=n;len++)
        for(int l=1,r=len;r<=n;l++,r++){
            dp[l][r][0]=min(dp[l+1][r][0]+(a[l+1]-a[l])*(sum[l]+sum[n]-sum[r]),dp[l+1][r][1]+(a[r]-a[l])*(sum[l]+sum[n]-sum[r]));
            dp[l][r][1]=min(dp[l][r-1][0]+(a[r]-a[l])*(sum[l-1]+sum[n]-sum[r-1]),dp[l][r-1][1]+(a[r]-a[r-1])*(sum[l-1]+sum[n]-sum[r-1]));
        }
    printf("%lld\n",min(dp[1][n][0],dp[1][n][1]));
}