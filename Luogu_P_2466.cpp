#include<bits/stdc++.h>
using namespace std;
pair<pair<int,int>,int> dt[1010];
int x[1010],y[1010],v[1010];
long long dp[1010][1010][2];
int n,c;
long long ans;
int main(){
    memset(dp,0x7f,sizeof dp);
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&dt[i].first.first);
    for(int i=1;i<=n;i++)
        scanf("%d",&dt[i].first.second);
    for(int i=1;i<=n;i++)
        scanf("%d",&dt[i].second);
    //dt[++n]={{c,0},0};
    sort(dt+1,dt+1+n);
    for(int i=1;i<=n;i++){
        x[i]=dt[i].first.first;
        y[i]=dt[i].first.second;
        v[i]=dt[i].second;
    }
    for(int i=1;i<=n;i++)
        ans+=y[i],v[i]+=v[i-1];
    for(int i=1;i<=n;i++)
        dp[i][i][0]=dp[i][i][1]=1ll*abs(x[i]-c)*v[n];
    for(int len=2;len<=n;len++)
        for(int l=1,r=len;r<=n;l++,r++){
            dp[l][r][0]=min(dp[l+1][r][0]+1ll*(x[l+1]-x[l])*(v[n]+v[l]-v[r]),
                            dp[l+1][r][1]+1ll*(x[r]-x[l])*(v[n]+v[l]-v[r]));
            dp[l][r][1]=min(dp[l][r-1][0]+(x[r]-x[l])*(v[n]+v[l-1]-v[r-1]),
                            dp[l][r-1][1]+(x[r]-x[r-1])*(v[n]+v[l-1]-v[r-1]));
        }
    ans-=min(dp[1][n][0],dp[1][n][1]);
    printf("%.3lf",(double)ans/1000.0);
}