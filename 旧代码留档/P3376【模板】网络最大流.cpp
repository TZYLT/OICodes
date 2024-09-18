#include<bits/stdc++.h>
using namespace std;
#define M 300300

int head[M],nextt[M],edge[M],ver[M],d[M],now[M],cnt;
void add(int x,int y,int z){
    ++cnt;ver[cnt]=y;edge[cnt]=z;nextt[cnt]=head[x];head[x]=cnt;
    ++cnt;ver[cnt]=x;edge[cnt]=0;nextt[cnt]=head[y];head[x]=cnt;
}
int s,t;
bool bfs(){
    memset(d,0,sizeof d);
    queue<int> q;q.push(s);
    d[s]=1;now[s]=head[s];
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
    for(int i=now[i];i&&rest;i=nextt[i]){
        now[i]=i;
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
        while(flow=getflow(s,(1<<30)))
            maxflow+=flow;
    return maxflow;        
}

int n,m;
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    printf("%d\n",dinic());
}