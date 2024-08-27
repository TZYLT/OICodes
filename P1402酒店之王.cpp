#include<bits/stdc++.h>
using namespace std;
#define M 200200
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
int n,p,q;
int num(int x,int st){
    if(st==0)return 2+x;
    else if(st==1)return 2+p+x;
    else if(st==2)return 2+p+n+x;
    else if(st==3)return 2+p+n+n+x;
}
int main(){
    scanf("%d%d%d",&n,&p,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=p;j++){
            int x;scanf("%d",&x);
            if(x==1)add(num(j,0),num(i,1),1);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=q;j++){
            int x;scanf("%d",&x);
            if(x==1)add(num(i,2),num(j,3),1);
        }
    for(int i=1;i<=n;i++)
        add(num(i,1),num(i,2),1);
    s=1;t=p+n+n+q+10;
    for(int i=1;i<=p;i++)
        add(s,num(i,0),1);
    for(int i=1;i<=q;i++)
        add(num(i,3),t,1);
    printf("%d\n",dinic());
}