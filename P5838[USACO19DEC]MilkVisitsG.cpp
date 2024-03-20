#include<bits/stdc++.h>
using namespace std;
#define M 300300
int head[M],nextt[M],ver[M],cnt;
int typ[M];
int n,m;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int _size[M],dep[M],hson[M],fa[M],top[M];
void dfsI(int x,int ffa){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=ffa){
            dfsI(ver[i],x);
            _size[x]+=_size[ver[i]];
            if(s<_size[ver[i]])s=_size[ver[i]],hson[x]=ver[i];
        }        
}
void dfsII(int x,int tp){
    top[x]=tp;
    if(!hson[x])return;
    dfsII(hson[x],tp);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa[x]&&ver[i]!=hson[x])
            dfsII(ver[i],ver[i]);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
struct node{
    int lc,rc,data;
}tree[50*M];
int root[M],tot;

int change(int rt,int l,int r,int x){
    int p=++tot;
    //printf("[%d,%d]:(%d,%d)\n",rt,p,l,r);
    //fflush(stdout);
    tree[p]=tree[rt];
    if(l==r){
        tree[p].data+=1;
        return p;
    }
    int mid=(l+r)>>1;
    if(x<=mid)tree[p].lc=change(tree[rt].lc,l,mid,x);
    else tree[p].rc=change(tree[rt].rc,mid+1,r,x);
    return p;
}

int ask(int rt,int l,int r,int x){
    if(l==r&&l==x) return tree[rt].data;
    int mid=(l+r)>>1;
    if(x<=mid)return ask(tree[rt].lc,l,mid,x);
    else return ask(tree[rt].rc,mid+1,r,x);
}

void dfs(int x,int f){
    //printf("[%d,%d]:\n",x,f);
    root[x]=change(root[f],1,n,typ[x]);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=f)dfs(ver[i],x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",typ+i);
    
    for(int i=1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfsI(1,0);
    dfsII(1,1);
    dfs(1,0);
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int lcaa=lca(x,y);
        int ans=ask(root[x],1,n,z)
                +ask(root[y],1,n,z)
                -ask(root[lcaa],1,n,z)
                -ask(root[fa[lcaa]],1,n,z);
        printf("%d",ans>0);
    }
}