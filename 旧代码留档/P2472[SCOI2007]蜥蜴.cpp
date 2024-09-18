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
int n,m,k,ans;
int id(int i,int j,int st){
    return n*m*st+(j-1)*n+i-1+5;
}
int inf=1<<28;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    s=1;t=n*m*2+10;
    for(int i=1;i<=n;i++){
        string ss;cin>>ss;
        for(int j=1;j<=m;j++){
            if(ss[j-1]=='0')continue;
            add(id(i,j,0),id(i,j,1),ss[j-1]-'0');
            for(int x=-k;x<=k;x++)
                for(int y=-k;y<=k;y++)
                    if(x*x+y*y<=k*k){
                        if((i+x)<=n&&(i+x)>=1&&(j+y)<=m&&(j+y)>=1)
                            add(id(i,j,1),id(i+x,j+y,0),inf);
                        else add(id(i,j,1),t,inf);
                    }
        }
    }
    for(int i=1;i<=n;i++){
        string ss;cin>>ss;
        for(int j=1;j<=m;j++)
            if(ss[j-1]=='L')
                add(s,id(i,j,0),1),ans++;
    }
    printf("%d\n",ans-dinic());
}