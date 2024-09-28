#include<bits/stdc++.h>
using namespace std;
#define M 1000200
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int low[M],dfn[M],st[M],h,tot,c;
int v[M];
void dfs(int x){
    low[x]=dfn[x]=++tot;
    st[++h]=x;
    for(int i=head[x];i;i=nextt[i]){
        if(!dfn[ver[i]]){
            dfs(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }else 
            if(!v[ver[i]])
                low[x]=min(low[x],dfn[ver[i]]);
    }
    if(dfn[x]==low[x]){
        ++c;
        while(st[h]!=x)
            v[st[h--]]=c;
        v[x]=c;h--;
    }
}
int n,m;
int in[M],w[M],p;
int ins[M];
vector<int> scc[M];
int main(){
    scanf("%d%d",&n,&p);
    memset(w,0x7f,sizeof w);
    for(int i=1;i<=p;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        w[x]=y;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i);

    
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=nextt[j])
            if(v[ver[j]]!=v[i])
                in[v[ver[j]]]++;

    for(int i=1;i<=n;i++)
        scc[v[i]].push_back(i);
    int ans=0;
    for(int i=1;i<=c;i++)
        if(in[i]==0){
            int t=0x3f3f3f3f,id=0;
            for(int k:scc[i])
                if(t>w[k])
                    t=w[k],id=k;
                else if(t==w[k])id=min(id,k);
                //t=min(t,w[k]);
            ans+=t;ins[id]=1;
        }

    queue<int> q;
    for(int i=1;i<=c;i++)
        if(in[i]==0){
        int f=0;
        for(int k:scc[i])
            if(w[k]<=20020)
                f=1;
        if(f)q.push(i);
    }
    while(q.size()){
        int x=q.front();q.pop();
        //printf("[%d]",x);
        for(int k:scc[x])
            ins[k]=1;
        for(int k:scc[x])
            for(int j=head[k];j;j=nextt[j])
                if(v[ver[j]]!=v[k]){
                    in[v[ver[j]]]--;
                    if(in[v[ver[j]]]==0)
                        q.push(v[ver[j]]);
                }
    }
    for(int i=1;i<=n;i++)
        if(w[i]<20020)
            ins[i]=1;
    for(int i=1;i<=n;i++)
        if(!ins[i]){
            printf("NO\n%d\n",i);
            return 0;
        }
    printf("YES\n%d\n",ans);

}
