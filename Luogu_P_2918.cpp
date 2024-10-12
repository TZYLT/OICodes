#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[55050];
int main(){
    scanf("%d%d",&n,&m);
    memset(dp,0x7f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int w,c;
        scanf("%d%d",&c,&w);
        for(int j=c;j<=m+5000;j++)
            dp[j]=min(dp[j],dp[j-c]+w);
    }
    int ans=0x7f7f7f7f;
    for(int i=m;i<=m+5000;i++)
        ans=min(ans,dp[i]);
    printf("%d\n",ans);
}