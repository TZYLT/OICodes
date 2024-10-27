#include<bits/stdc++.h>
using namespace std;
int dp[55][100100][2];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    memset(dp,0xcf,sizeof dp);
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    for(int i=1;i<=n;i++){
        int mw,t;
        scanf("%d%d",&mw,&t);
        for(int j=0;j<=m;j++)
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
        for(int j=m;j>=mw;j--)
            dp[i][j][1]=dp[i][j-mw][0];
        for(int j=1;j<=t;j++){
            int w,c;
            scanf("%d%d",&c,&w);
            for(int k=m;k>=c;k--)
                dp[i][k][1]=max(dp[i][k][1],dp[i][k-c][1]+w);
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++)
        ans=max(ans,dp[n][i][0]);
    for(int i=1;i<=m;i++)
        ans=max(ans,dp[n][i][1]);
    printf("%d\n",ans);  
}