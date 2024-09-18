#include<bits/stdc++.h>
using namespace std;
int dp[310][310];
int n,m;
int head[1010],nextt[1010],ver[1010],cnt;
int w[1010];
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
void dfs(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            for(int j=m;j>=1;j--)
                for(int k=0;k<j;k++)
                    dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[ver[i]][k]);
        }
}
int main(){
    scanf("%d%d",&n,&m);m++;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d%d",&k,&dp[i+1][1]);
        add(i+1,k+1);
        add(k+1,i+1);
    }
    dfs(1,0);
    printf("%d\n",dp[1][m]);
}