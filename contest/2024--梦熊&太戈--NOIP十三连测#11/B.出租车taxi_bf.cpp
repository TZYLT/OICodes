#include<bits/stdc++.h>
using namespace std;
int dp[5050][5050];
int n,a[100100],b[100100];
int main(){
    //freopen("taxi.in","r",stdin);
    //freopen("taxi.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    memset(dp,0x7f,sizeof dp);
    dp[n][n]=0;
    for(int i=n;i>=0;i--)
        for(int j=n;j>=0;j--){
            if(i>=1)dp[i-1][j]=min(dp[i-1][j],dp[i][j]+1);
            if(j>=1)dp[i][j-1]=min(dp[i][j-1],dp[i][j]+1);
            if(a[n-i+1]!=b[n-j+1]&&i>=1&&j>=1)dp[i-1][j-1]=min(dp[i-1][j-1],dp[i][j]+1);
        }
    printf("%d\n",dp[0][0]);
}