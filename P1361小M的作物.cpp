#include<bits/stdc++.h>
using namespace std;
#define M 2000200
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
int num(int x,int st){
    if(st==0)return 3+x;
    else if(st==1)return 3+x+n;
    else if(st==2)return 3+x+n+m;
}
int ans=0;
const int inf=1<<28;
int l[M],r[M];
int main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        ans+=x;l[i]=x;
    }
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        ans+=x;r[i]=x;
    }
    scanf("%d",&m);
    s=1;t=n+m+m+10;
    for(int i=1;i<=n;i++)
        add(s,num(i,0),l[i]),
        add(num(i,0),t,r[i]);
    
    
    for(int i=1;i<=m;i++){
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        ans+=a+b;
        add(s,num(i,1),a);
        add(num(i,2),t,b);
        for(int j=1;j<=k;j++){
            int x;scanf("%d",&x);
            add(num(i,1),num(x,0),inf);
            add(num(x,0),num(i,2),inf);
        }
    }
    printf("%d\n",ans-dinic());
}