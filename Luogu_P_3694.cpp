#include<bits/stdc++.h>
using namespace std;
int sum[100100][25];
int dp[1<<20];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j];
        sum[i][x]++;
    }
    memset(dp,0x7f,sizeof dp);
    dp[0]=0;
    for(int i=0;i<(1<<m);i++){
        int l=0;
        for(int j=1;j<=m;j++)
            if((i>>(j-1))&1)
                l+=sum[n][j];
        for(int j=1;j<=m;j++)
            if(!((i>>(j-1))&1)){
                int r=l+sum[n][j];
                dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+r-l-(sum[r][j]-sum[l][j]));
            }
    }
    printf("%d\n",dp[(1<<m)-1]);
}