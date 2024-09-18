#include<bits/stdc++.h>
using namespace std;
int dp[40][55][55];
int n,m;
#define M 100100
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    q.push(make_pair(0,1));
    while(q.size()){
        int x=q.top().second;
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=nextt[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        dp[0][x][y]=1;
    }
    for(int i=1;i<=32;i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
                for(int k=1;k<=n;k++)
                    dp[i][x][y]|=dp[i-1][x][k]&dp[i-1][k][y];
    for(int i=0;i<=32;i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
                if(dp[i][x][y])
                    add(x,y,1);
    dijkstra();
    printf("%d\n",d[n]);
}