int dp[1010][1010];
int a[1010],n;
int sol(){
    for(int i=1;i<=n;i++)
        dp[i][i]=a[i];
    for(int len=2;len<=n;i++)
        for(int l=1,r=len;r<=n;l++,r++)
            if(dp[l][r-1]&&dp[l+1][r])dp[l][r]=0;
            else dp[l][r]=1;
    return dp[1][n];
}