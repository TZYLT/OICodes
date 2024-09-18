#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int _size[M],dep[M],hson[M],fa[M],top[M],dfn[M],idfn[M],tot;
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
    top[x]=tp;dfn[x]=++tot;
    idfn[dfn[x]]=x;
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


int l[4*M+1],r[4*M+1];
int maxx[4*M+1],id[4*M+1];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]=0;
        id[p]=li;
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
    id[p]=(maxx[p*2]>=maxx[p*2+1])?id[p*2]:id[p*2+1];
}
void change(int p,int x,int d){
    
    if(l[p]==x&&x==r[p]){
        maxx[p]+=d;
        return; 
    }
    int mid=(l[p]+r[p])/2;
    if(x<=mid)change(p*2,x,d);
    if(x>mid)change(p*2+1,x,d);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
    id[p]=(maxx[p*2]>=maxx[p*2+1])?id[p*2]:id[p*2+1];
   
}
pair<int,int> ask(int p,int li,int ri){
    
    if(li<=l[p]&&ri>=r[p]) return make_pair(maxx[p],id[p]);
    int mid=(l[p]+r[p])/2;
    pair<int,int> v,t;
    v.first=-114514;
    if(li<=mid)t=ask(p*2,li,ri);
    if(t.first>=v.first)v=t;

    if(ri>mid)t=ask(p*2+1,li,ri);
    if(t.first>=v.first)v=t;

    return v;
} 
vector<int> opt[M];

void add_t(int x,int y,int d){
    if(dep[x]<dep[y])swap(x,y);

    while(dep[top[x]]>dep[y]){
        
        opt[dfn[x]+1].push_back(-d);
        opt[dfn[top[x]]].push_back(d);
        x=fa[top[x]];
    }
    
    opt[dfn[x]+1].push_back(-d);
    opt[dfn[y]].push_back(d);
}

int out[M];
int n,m,x,y,z;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfsI(1,0);
    dfsII(1,1);

    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add_t(x,lca(x,y),z);
        add_t(y,lca(x,y),z);
        add_t(lca(x,y),lca(x,y),-z);
    }
    build(1,1,100000);
    for(int i=1;i<=n;i++){
        for(auto c:opt[i])
            change(1,abs(c),c>0?1:-1);
        pair<int,int> ans=ask(1,1,100000);
        out[idfn[i]]=ans.first==0?0:ans.second;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",out[i]);
}