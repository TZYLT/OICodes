#include<bits/stdc++.h>
using namespace std;
int n,x[1010],q[1010],dp[1010][1010],ans;
pair<int,int> dt[1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",x+i,q+i),dt[i]={x[i],q[i]};
    sort(dt+1,dt+1+n);
    for(int i=1;i<=n;i++)
        x[i]=dt[i].first,q[i]=dt[i].second;
    if(n==1){
        printf("%d\n",q[1]);
        return 0;
    }
    for(int j=1;j<=n;j++){
        dp[j][j]=q[j];
        for(int i=j+1,k=j+1;i<=n;i++){
            dp[i][j]=dp[i-1][j]-q[i-1];
            while(k>1&&x[j]-x[k-1]<=x[i]-x[j])
                dp[i][j]=max(dp[i][j],dp[j][--k]);
            dp[i][j]+=q[i];
            ans=max(ans,dp[i][j]);
        }
    }
    memset(dp,0,sizeof dp);
    for(int j=n;j>=1;j--){
        dp[j][j]=q[j];
        for(int i=j-1,k=j-1;i>=1;i--){
            dp[i][j]=dp[i+1][j]-q[i+1];
            while(k<n&&x[k+1]-x[j]<=x[j]-x[i])
                dp[i][j]=max(dp[i][j],dp[j][++k]);
            dp[i][j]+=q[i];
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d",ans);
}