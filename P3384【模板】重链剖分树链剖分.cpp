#include<bits/stdc++.h>
using namespace std;
#define M 200200
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}

int _size[M],dep[M],hson[M],fa[M],top[M];
int dfn[M],range[M],tot;
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
    if(!hson[x])return range[x]=tot,void();
    dfsII(hson[x],tp);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa[x]&&ver[i]!=hson[x])
            dfsII(ver[i],ver[i]);
    range[x]=tot;
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
long long sum[4*M+1],_add[4*M+1];
int data[M+1],w[M];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        sum[p]=data[li];
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    sum[p]=sum[p*2]+sum[p*2+1];
}
void spread(int p){
    if(_add[p]){
        sum[p*2]+=_add[p]*(r[p*2]-l[p*2]+1);
        sum[p*2+1]+=_add[p]*(r[p*2+1]-l[p*2+1]+1);
        _add[p*2]+=_add[p];
        _add[p*2+1]+=_add[p];
        _add[p]=0;
    }
}
void change(int p,int li,int ri,int d){
    if(li<=l[p]&&ri>=r[p]){
        sum[p]+=(long long)d*(r[p]-l[p]+1);
        _add[p]+=d;
        return; 
    }
    spread(p);
    int mid=(l[p]+r[p])/2;
    if(li<=mid)change(p*2,li,ri,d);
    if(ri>mid)change(p*2+1,li,ri,d);
    sum[p]=sum[p*2]+sum[p*2+1];
}
long long ask(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return sum[p];
    spread(p);
    int mid=(l[p]+r[p])/2;
    long long v=0;
    if(li<=mid)v+=ask(p*2,li,ri);
    if(ri>mid)v+=ask(p*2+1,li,ri);
    return v;
} 
void add(int x,int d){
    while(x){
        change(1,dfn[top[x]],dfn[x],d);
        x=fa[top[x]];
    }
}
int n,m,rt,p,op,x,y,z;
int ask(int x){
    int ans=0;
    while(x){
        ans=(ans+ask(1,dfn[top[x]],dfn[x]))%p;
        x=fa[top[x]];
    }
    return ans;
}


int main(){
    scanf("%d%d%d%d",&n,&m,&rt,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y,0);
        add(y,x,0);
    }
    dfsI(rt,0);
    dfsII(rt,rt);
    for(int i=1;i<=n;i++)
        data[dfn[i]]=w[i];
    build(1,1,n);
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&x,&y,&z);
            z%=p;
            add(x,z);add(y,z);
            add(lca(x,y),-z);
            add(fa[lca(x,y)],-z);
        }else if(op==2){
            scanf("%d%d",&x,&y);
            printf("%d\n",((ask(x)+ask(y)-ask(lca(x,y))-ask(fa[lca(x,y)]))%p+p)%p);
        }else if(op==3){
            scanf("%d%d",&x,&y);
            y%=p;
            change(1,dfn[x],range[x],y);
        }else {
            scanf("%d",&x);
            printf("%d\n",(ask(1,dfn[x],range[x])%p+p)%p);
        }
    }
    
}