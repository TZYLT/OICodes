#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10;
const int maxm=2000+10;
int n,m,p;
int x[maxn],y[maxn];
int low[maxn],high[maxn];
int dp[maxn][maxm];
bool e[maxn];
int main() {
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;++i) 
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;++i) 
        low[i]=1,high[i]=m;
    int a,b,c;
    for(int i=1;i<=p;++i) {
        scanf("%d%d%d",&a,&b,&c);
        e[a]=1;
        low[a]=b+1;
        high[a]=c-1;
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1; i<=m; ++i) dp[0][i]=0;
    for(int i=1; i<=n; ++i) {
        for(int j=x[i]+1; j<=m+x[i]; ++j)
            dp[i][j]=min(dp[i-1][j-x[i]]+1,dp[i][j-x[i]]+1);
        for(int j=m+1; j<=m+x[i]; ++j)
            dp[i][m]=min(dp[i][m],dp[i][j]);
        for(int j=1; j<=m-y[i]; ++j)
            dp[i][j]=min(dp[i][j],dp[i-1][j+y[i]]);
        for(int j=1; j<low[i]; ++j)
            dp[i][j]=dp[0][0];
        for(int j=high[i]+1; j<=m; ++j)
            dp[i][j]=dp[0][0];
    }
    int ans=dp[0][0];
    for(int j=1;j<=m;++j) {
        ans=min(ans,dp[n][j]);
    }
    if(ans<dp[0][0]) printf("1\n%d\n",ans);
    else{
        int i,j;
        for(i=n;i>=1;i--) {
            for(j=1;j<=m;++j) 
                if(dp[i][j]<dp[0][0]) break;
            if(j<=m) break;
        }
        ans=0;
        for(int j=1;j<=i;++j)
            if(e[j]) ans++;
        printf("0\n%d\n",ans);
    }
    return 0;
}