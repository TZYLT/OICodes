#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int l,n,b;
vector<pair<int,pair<int,int>> > qs[1010];
int main(){
    scanf("%d%d%d",&l,&n,&b);
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        qs[a].push_back({b,{c,d}});
    }
    memset(dp,0xcf,sizeof dp);
    //for(int i=1;i<=b;i++)
        dp[0][0]=0;
    for(int i=0;i<=l;i++)
        for(auto c:qs[i])
            for(int j=0;j<=b;j++)
                if(i+c.first<=l)
                    dp[i+c.first][j+c.second.second]=max(dp[i+c.first][j+c.second.second],dp[i][j]+c.second.first);
    int ans=0xcfcfcfcf;
    for(int i=1;i<=b;i++)
        ans=max(ans,dp[l][i]);
    if(ans>=-1001000)printf("%d\n",ans);
    else printf("-1\n");
    
}