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
const int inf=1<<29;
int ans;
int n,m;
int num(int i,int j,int st){
    return 2+(i-1)+(j-1)*n+st*n*m;
}

int main(){
    scanf("%d%d",&n,&m);
    s=n*m*5+5;t=n*m*5+6;
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);ans+=x;
            add(s,num(i,j,0),x);
        }
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);ans+=x;
            add(num(i,j,0),t,x);
        }
    for(int i=1;i<n;i++)   
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);ans+=x;
            add(s,num(i,j,1),x);
            add(num(i,j,1),num(i,j,0),inf);
            add(num(i,j,1),num(i+1,j,0),inf);
        }
    for(int i=1;i<n;i++)   
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);ans+=x;
            add(num(i,j,2),t,x);
            add(num(i,j,0),num(i,j,2),inf);
            add(num(i+1,j,0),num(i,j,2),inf);
        }
    for(int i=1;i<=n;i++)   
        for(int j=1;j<m;j++){
            int x;scanf("%d",&x);ans+=x;
            add(s,num(i,j,3),x);
            add(num(i,j,3),num(i,j,0),inf);
            add(num(i,j,3),num(i,j+1,0),inf);
        }
    for(int i=1;i<=n;i++)   
        for(int j=1;j<m;j++){
            int x;scanf("%d",&x);ans+=x;
            add(num(i,j,4),t,x);
            add(num(i,j,0),num(i,j,4),inf);
            add(num(i,j+1,0),num(i,j,4),inf);
        }
    printf("%d\n",ans-dinic());
}