#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[550][550];
pair<int,int> tp[550][550];
int w[550][550];
int main(){
    memset(dp,0xcf,sizeof dp);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&w[i][j]);
    for(int i=0;i<=m;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(dp[i][j-1]>dp[i-1][j-1]+w[i][j])
                dp[i][j]=dp[i][j-1],tp[i][j]={i,j-1};
            else dp[i][j]=dp[i-1][j-1]+w[i][j],tp[i][j]={i-1,j-1};
        }

    printf("%d\n",dp[n][m]);
    vector<int> ans;
    int l=n,r=m;
    while(l&&r){
        if(l==tp[l][r].first+1&&r==tp[l][r].second+1)
            ans.push_back(r);
        l=tp[l][r].first;r=tp[l][r].second;
    }
    for(int i=ans.size()-1;i>=0;i--)
        printf("%d ",ans[i]);
}