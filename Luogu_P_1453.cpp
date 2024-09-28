#include<bits/stdc++.h>
using namespace std;
#define M 2002000
int head[M],nextt[M],ver[M],cnt=1;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[1001000],cx,cy,eg;
void fc(int x,int fa){
    v[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if((i^1)!=fa){
            if(v[ver[i]]==1){cx=x;cy=ver[i];eg=i;continue;}
            fc(ver[i],i);
        }
}
long long dp[1002000][2];
int w[1002000];
void dfs(int x,int fa,int p){
    dp[x][0]=0;dp[x][1]=w[x];
    for(int i=head[x];i;i=nextt[i])
        if(i!=p&&i!=(p^1)&&(i^1)!=fa){
            dfs(ver[i],i,p);
            dp[x][0]+=max(dp[ver[i]][1],dp[ver[i]][0]);
            dp[x][1]+=dp[ver[i]][0];
        }
}
int n;
long long ans;
double r;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);x++,y++;
        add(y,x);add(x,y);
    }
    scanf("%lf",&r);

    fc(1,0);
    dfs(cx,0,eg);
    long long t=dp[cx][0];
    dfs(cy,0,eg);
    ans=max(dp[cy][0],t);
        
    printf("%.1lf\n",r*ans);
}