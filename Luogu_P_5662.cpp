#include<bits/stdc++.h>
using namespace std;
int dp[100010],p[105][105];
int t,n,m;
int ans;
int main(){
    scanf("%d%d%d",&t,&n,&m);
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
    ans=m;
    for(int k=1;k<=t;k++){
        memset(dp,0xcf,sizeof dp);
        dp[ans]=ans;
        for(int i=1;i<=n;i++)
            for(int j=ans;j>=p[k][i];j--)
                dp[j-p[k][i]]=max(dp[j-p[k][i]],dp[j]+p[k+1][i]-p[k][i]);
        int mm=0;
        for(int i=0;i<=ans;i++)
            mm=max(mm,dp[i]);
        ans=mm;
    }
    printf("%d\n",ans);
}