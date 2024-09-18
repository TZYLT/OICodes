#include<bits/stdc++.h>
using namespace std;
#define M 500200
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
int n,m;
int inf=1<<28;
int id(int i,int j){
    return 3+i-1+(j-1)*n;
}
int main(){
    scanf("%d%d",&n,&m);
    s=1;t=n*m+10;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int x;scanf("%d",&x);
            if(i<n)add(id(i,j),id(i+1,j),1);
            if(j<m)add(id(i,j),id(i,j+1),1);
            if(i>1)add(id(i,j),id(i-1,j),1);
            if(j>1)add(id(i,j),id(i,j-1),1);
            if(x==1)add(id(i,j),t,inf);
            if(x==2)add(s,id(i,j),inf);
        }
    printf("%d\n",dinic());
}