#include<bits/stdc++.h>
using namespace std;
#define M 2001000
int head[M],nextt[M],ver[M],cnt;
int Head[M],Nextt[M],Ver[M],Cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,m;

int dfn[M],low[M],c,id;
int st[M],h;
vector<int> ans[M];
void dfs(int x,int fa){
    dfn[x]=low[x]=++id;
    st[++h]=x;
    int son=0;
    for(int i=head[x];i;i=nextt[i]){
        if(ver[i]!=fa){
            if(dfn[ver[i]]==0){
                ++son;
                dfs(ver[i],x);
                low[x]=min(low[x],low[ver[i]]);
                if(low[ver[i]]>=dfn[x]){
                    ++c;
                    while(st[h]!=ver[i]){
                        ans[c].push_back(st[h]);
                        h--;
                    }
                    ans[c].push_back(ver[i]);
                    h--;
                    ans[c].push_back(x);
                }
            }
            else low[x]=min(low[x],dfn[ver[i]]);
        }   
    } 
    if(son==0&&fa==0)ans[++c].push_back(x);
}

int d[M],w[M];
void addnew(int x,int y){
    ++Cnt;
    Ver[Cnt]=y;
    Nextt[Cnt]=Head[x];
    Head[x]=Cnt;
}
    
int _size[M],dep[M],hson[M],fa[M],top[M];
void dfsI(int x,int ffa){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    for(int i=Head[x];i;i=Nextt[i])
        if(Ver[i]!=ffa){
            dfsI(Ver[i],x);
            _size[x]+=_size[Ver[i]];
            if(s<_size[Ver[i]])s=_size[Ver[i]],hson[x]=Ver[i];
        }        
}
void dfsII(int x,int tp){
    top[x]=tp;
    if(!hson[x])return;
    dfsII(hson[x],tp);
    for(int i=Head[x];i;i=Nextt[i])
        if(Ver[i]!=fa[x]&&Ver[i]!=hson[x])
            dfsII(Ver[i],Ver[i]);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
void dfsans(int x,int f){
    w[x]=w[f]+(x>n?1:0);
    for(int i=Head[x];i;i=Nextt[i])
        if(Ver[i]!=f){
        dfsans(Ver[i],x);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    h=0;
    dfs(1,0);
    for(int i=1;i<=c;i++){
        for(auto x:ans[i]){
            addnew(x,i+n);
            addnew(i+n,x);
        }
    }
    dfsI(1,0);
    dfsII(1,1);
    dfsans(1,0);
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=w[x]+w[y]-w[lca(x,y)]
                -w[fa[lca(x,y)]]+1;
        printf("%d\n",ans);
    }
}