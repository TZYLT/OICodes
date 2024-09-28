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
int in[M];
int main(){
    scanf("%d%d",&n,&m);
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
    int ans=0;
    for(int i=1;i<=c;i++)
        ans+=(in[i]==0);
    printf("%d\n",ans);
}