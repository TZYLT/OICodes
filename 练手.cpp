#include<bits/stdc++.h>
using namespace std;
//link cut
int head[M],ver[M],nextt[M],cnt;
void add(int x,int y){
    ver[++cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}

int hson[M],top[M],size[M],dep[M],f[M];
void dfsi(int x,int fa){
    size[x]=1;f[x]=fa;dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=nextt[i])
        if(fa!=ver[i]){
            dfsi(ver[i],x);
            size[x]+=size[ver[i]];
            hson[x]=size[hson[i]]<size[ver[i]]?ver[i]:hson[x];
        }
}

void dfsii(int x,int fa,int tp){
    top[x]=tp;
    if(!hson[x])return;
    dfsii(hson[x],x,tp);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa&&ver[i]!=hson[x])
            dfs(ver[i],ver[i]);
}

int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=f[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}


//kruskal
struct eg{
    int u,v,w; 
}mmap[M];
int cnt;
bool cmp(eg x,eg y){
    return x.w<y.w;
}
int ans;
void k(void){
    sort(mmap+1,mmap+1+cnt,cmp)l;
    for(int i=1;i<=cnt;i++){
        if(get(mmap[i].u)==get(mmap[i].v))continue;
        merge(mmap[i].u,mmap[i].v);
        ans+=mmap[i].w;
    }
}