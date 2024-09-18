#include<bits/stdc++.h>
using namespace std;
#define M 16002000
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
int n,m,x;
int id(int i,int j){
    return 2+i+j*n;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++){
            scanf("%d",&x);
            add(id(i,j),id(i,j+1),x);
            add(id(i,j+1),id(i,j),x);
        }
    for(int i=1;i<n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&x);
            add(id(i,j),id(i+1,j),x);
            add(id(i+1,j),id(i,j),x);
        }
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            scanf("%d",&x);
            add(id(i,j),id(i+1,j+1),x);
            add(id(i+1,j+1),id(i,j),x);
        }
    s=id(1,1);t=id(n,m);
    printf("%d",dinic());        
}