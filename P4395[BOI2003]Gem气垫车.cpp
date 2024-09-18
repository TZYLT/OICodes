#include<bits/stdc++.h>
using namespace std;
#define M 100100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dp[100100][30];
int ans=0x3f3f3f3f;
void dfs(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)dfs(ver[i],x);
    for(int j=1;j<=25;j++){
        dp[x][j]=j;
        for(int i=head[x];i;i=nextt[i])
            if(ver[i]!=fa){
                int t=0x3f3f3f3f;
                for(int k=1;k<=25;k++)
                    if(k!=j)t=min(dp[ver[i]][k],t);
                dp[x][j]+=t;
            }
    }
}
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(dp,0x3f,sizeof dp);
    dfs(1,0);
    for(int i=1;i<=25;i++)
        ans=min(ans,dp[1][i]);
    printf("%d\n",ans);
}