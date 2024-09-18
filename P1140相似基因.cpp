#include<bits/stdc++.h>
using namespace std;
int dp[110][110],n,m;
int w[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-114514}};
int a[110],b[110];
string s,t;
int main(){
    cin>>n>>s;
    cin>>m>>t;
    for(int i=0;i<n;i++){
        if(s[i]=='A')a[i+1]=0;
        else if(s[i]=='C')a[i+1]=1;
        else if(s[i]=='G')a[i+1]=2;
        else if(s[i]=='T')a[i+1]=3;
        dp[i+1][0]=dp[i][0]+w[a[i+1]][4];
    }
    for(int i=0;i<m;i++){
        if(t[i]=='A')b[i+1]=0;
        else if(t[i]=='C')b[i+1]=1;
        else if(t[i]=='G')b[i+1]=2;
        else if(t[i]=='T')b[i+1]=3;
        dp[0][i+1]=dp[0][i]+w[4][b[i+1]];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=max({dp[i-1][j-1]+w[a[i]][b[j]],dp[i-1][j]+w[a[i]][4],dp[i][j-1]+w[4][b[j]]});
    printf("%d\n",dp[n][m]);
}