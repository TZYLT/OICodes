#include<bits/stdc++.h>
using namespace std;
#define M 1000200
int head[M],nextt[M],edge[M],ver[M],d[M],now[M],cnt=1;
void add(int x,int y,int z){
    ++cnt;ver[cnt]=y;edge[cnt]=z;nextt[cnt]=head[x];head[x]=cnt;
    ++cnt;ver[cnt]=x;edge[cnt]=0;nextt[cnt]=head[y];head[y]=cnt;
}
int s,t;
bool bfs(){
    memset(d,0,sizeof d);
    queue<int> q;
    q.push(s);d[s]=1;now[s]=head[s];
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i])
            if(edge[i]&&!d[ver[i]]){
                q.push(ver[i]);
                now[ver[i]]=head[ver[i]];
                d[ver[i]]=d[x]+1;
                if(ver[i]==t)return 1;
            }
    }
    return 0;
}
int getflow(int x,int flow){
    if(x==t)return flow;
    int rest=flow;
    for(int i=now[x];i&&rest;i=nextt[i]){
        now[x]=i;
        if(edge[i]&&d[ver[i]]==d[x]+1){
            int k=getflow(ver[i],min(rest,edge[i]));
            if(!k)d[ver[i]]=0;
            edge[i]-=k;edge[i^1]+=k;
            rest-=k;
        }
    }
    return flow-rest;
}
int dinic(){
    int flow,maxflow=0;
    while(bfs())
        while(flow=getflow(s,(1<<29)))
            maxflow+=flow;
    return maxflow;        
}
const int inf=1<<28;
int n,m,k;int ans;
int num(int i,int j){
    return 2+(i-1)+(j-1)*n;
}
int dx[8]={1,3,3,1,-1,-3,-3,-1},dy[8]={-3,-1,1,3,3,1,-1,-3};
int v[500][500];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    s=1;t=n*m+10;
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x][y]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(v[i][j]==0){
                int x=1;ans+=x;
                if(i&1){
                    add(s,num(i,j),x);
                    for(int k=0;k<8;k++)
                        if(i+dx[k]>=1&&i+dx[k]<=n&&j+dy[k]>=1&&j+dy[k]<=m)
                            add(num(i,j),num(i+dx[k],j+dy[k]),inf);
                }else add(num(i,j),t,x);
            }
    printf("%d\n",ans-dinic());
}