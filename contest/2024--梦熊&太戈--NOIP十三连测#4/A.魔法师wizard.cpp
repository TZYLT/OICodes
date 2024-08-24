#include<bits/stdc++.h>
using namespace std;
#define M 19
int w[M][M],c[M][M],n,m;
int dp[1<<M][M],g[1<<M][M];
pair<int,int> pt[1<<M][M];
int main(){
    freopen("wizard.in","r",stdin);
    freopen("wizard.out","w",stdout);
    memset(dp,0x7f,sizeof dp);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&w[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    for(int i=1;i<=n;i++)
        dp[1<<(i-1)][i]=0;
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(((i>>(k-1))&1)==0){
                    if(dp[i|(1<<(k-1))][k]>dp[i][j]+w[j][k]&&g[i][j]+c[j][k]<=m){
                        dp[i|(1<<(k-1))][k]=dp[i][j]+w[j][k];
                        g[i|(1<<(k-1))][k]=g[i][j]+c[j][k];
                        pt[i|(1<<(k-1))][k]=make_pair(i,j);
                    }
                }
    int ans=0x7f7f7f7f,t=0;
    for(int i=1;i<=n;i++)
        if(ans>dp[(1<<n)-1][i])ans=dp[(1<<n)-1][i],t=i;
    printf("%d\n",ans);
    pair<int,int> id((1<<n)-1,t);
    vector<int> path;
    while(id!=make_pair(0,0)){
        path.push_back(id.second);
        id=pt[id.first][id.second];
    }
    while(path.size()){
        printf("%d ",path.back());
        path.pop_back();
    }
}