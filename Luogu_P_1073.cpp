#include<bits/stdc++.h>
using namespace std;
#define M 1000100
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dfn[M],v[M],st[M],low[M],h,tot,c;
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    st[++h]=x;
    for(int i=head[x];i;i=nextt[i])
        if(!dfn[ver[i]]){
            tarjan(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }else if(!v[ver[i]])
            low[x]=min(low[x],dfn[ver[i]]);
    if(low[x]==dfn[x]){
        ++c;
        while(st[h]!=x)
            v[st[h--]]=c;
        v[st[h--]]=c;
    }
}
int dp[M],in[M];
int n,m;
int p[M],cp[M],tag[M];
queue<int> q;
vector<int> g[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",p+i);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(z==1){
            add(x,y);
        }else{
            add(x,y);
            add(y,x);
        }
    }//printf("sb\n");
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nextt[j])
            if(v[i]!=v[ver[j]])
                g[v[i]].push_back(v[ver[j]]);
    memset(cp,0x3f,sizeof cp);
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++)
        cp[v[i]]=min(cp[v[i]],p[i]);
    // for(int i=1;i<=c;i++)
    //     if(!in[i])
    //         q.push(i),printf("%d ",i);
    q.push(v[1]);
    while(q.size()){
        int x=q.front();q.pop();
        tag[x]=1;
        for(int y:g[x])
            if(!tag[y])q.push(y);
    }

    for(int i=1;i<=n;i++)
        if(tag[v[i]])
        for(int j=head[i];j;j=nextt[j])
            if(v[i]!=v[ver[j]]&&tag[v[ver[j]]])
                in[v[ver[j]]]++;
    for(int i=1;i<=c;i++)
        g[i].clear();
    for(int i=1;i<=n;i++)
        if(tag[v[i]])
        for(int j=head[i];j;j=nextt[j])
            if(v[i]!=v[ver[j]]&&tag[v[ver[j]]])
                g[v[i]].push_back(v[ver[j]]);

    q.push(v[1]);
    while(q.size()){
        int x=q.front();q.pop();
        dp[x]=min(dp[x],cp[x]);
        for(int y:g[x]){
            dp[y]=min(dp[y],dp[x]);
            in[y]--;
            if(!in[y])q.push(y);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(tag[v[i]])ans=max(ans,p[i]-dp[v[i]]);
    printf("%d",ans);
}