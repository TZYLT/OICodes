#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],ver[M],w[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dp[M][25];
int n,k;
void dfs(int x,int fa){
    dp[x][0]=w[x];
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            for(int j=1;j<=k;j++)
                dp[x][j]+=dp[ver[i]][j-1];
        }
}
void dfs2(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            for(int j=k;j>=2;j--)  
                dp[ver[i]][j]-=dp[ver[i]][j-2];
            for(int j=1;j<=k;j++)  
                dp[ver[i]][j]+=dp[x][j-1];
            dfs2(ver[i],x);
        }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=0;j<=k;j++)
            sum+=dp[i][j];
        printf("%d\n",sum);
    }

}