#include<bits/stdc++.h>
using namespace std;
#define M 600600
int head[M],nextt[M],edge[M],tag1[M],tag[M],tag2[M],ver[M],cnt=1;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M],d[M];
priority_queue<pair<int,int> > q;
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[s]=0;
    q.push(make_pair(0,s));
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
int ans=0;
int n,m,s1,s2,t1,t2;
int vis[M],vv[M],in[M],dp[M];
int dfs(int x){
    if(x==t1)return vis[x]=1;
    if(vis[x])return 1;
    vv[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(tag1[i]){
            if(!vv[ver[i]]) vis[x]|=dfs(ver[i]);
            else vis[x]|=vis[ver[i]];
        }
            
    return vis[x];
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra(s1);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nextt[j])
            if(d[ver[j]]==d[i]+edge[j])
                tag1[j]=1;
    dijkstra(s2);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nextt[j])
            if(d[ver[j]]==d[i]+edge[j])
                tag2[j]=1,in[ver[j]]++;
    dfs(s1);
    for(int i=1;i<=n;i++)
        if(vis[i])
        for(int j=head[i];j;j=nextt[j])
            if(tag1[j]&&vis[ver[j]])
                tag[j]=1;
    queue<int> q;
    q.push(s2);
    while(q.size()){
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nextt[i])
            if(tag2[i]){
                dp[ver[i]]=max(dp[ver[i]],dp[x]+edge[i]*(tag[i]||tag[i^1]));
                in[ver[i]]--;
                if(!in[ver[i]])q.push(ver[i]);
            }
    }
    
    printf("%d\n",dp[t2]);
}   