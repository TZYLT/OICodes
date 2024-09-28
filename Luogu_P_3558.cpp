#include<bits/stdc++.h>
using namespace std;
int dp[1001000][3];
int a[1001000];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    memset(dp,0x7f,sizeof dp);
    dp[1][a[1]+1]=0;
    for(int i=0;i<n;i++){
        if(a[i+1]==-1){
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+2);
        }else if(a[i+1]==0){
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+1);
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+1);
        }else{
            dp[i+1][2]=min(dp[i+1][2],dp[i][0]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+1);
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+2);
            dp[i+1][2]=min(dp[i+1][2],dp[i][1]);
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]);
        }
    }
    int ans=min({dp[n][0],dp[n][1],dp[n][2]});
    if(ans>2*n)printf("BRAK\n");
    else printf("%d\n",ans);
}