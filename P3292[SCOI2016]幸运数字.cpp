#include<bits/stdc++.h>
using namespace std;

int head[50050],nextt[50050],ver[50050],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
struct line{
    long long data[65];
    void add(long long x){
        for(int i=62;i>=0;i--)
            if(x>>i&1){
                if(!data[i])return data[i]=x,void();
                else x^=data[i];
            }
    }
    void merge(line x){
        for(int i=0;i<=64;i++)
            add(x.data[i]);
    }
    void clear(void){
        for(int i=0;i<=64;i++)
            data[i]=0;
    }
};

line f[15][20020];
long long a[20020];int fa[15][20020];
int _size[20020],dep[20020],hson[20020],top[20020];
void dfsI(int x,int ffa){
    int s=-1;
    _size[x]=1;fa[0][x]=ffa;
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
        if(ver[i]!=fa[0][x]&&ver[i]!=hson[x])
            dfsII(ver[i],ver[i]);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        x=fa[0][top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
line ask(int x,int y){
    if(x==y)return f[0][x];
    if(dep[x]<dep[y])swap(x,y);
    int len=dep[x]-dep[y]+1,k=x,d=len-(1<<__lg(len));
    line t=f[__lg(len)][x];
    for(int i=0;d;i++,d>>=1)
        if(d&1)k=fa[i][k];
    //printf("[DEBUG]:k:%d Rlen:%d\n",k,(1<<__lg(len)));
    t.merge(f[__lg(len)][k]);
    return t;
}
int n,q;
int main(){
    
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfsI(1,0);
    dfsII(1,1);
    for(int i=1;i<=14;i++)
        for(int j=1;j<=n;j++)
            fa[i][j]=fa[i-1][fa[i-1][j]];
    
    for(int i=1;i<=n;i++)
        f[0][i].add(a[i]);
    
    for(int i=1;i<=14;i++)
        for(int j=1;j<=n;j++){
            f[i][j]=f[i-1][j];
            f[i][j].merge(f[i-1][fa[i-1][j]]);
        }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int l=lca(x,y);

        line a=ask(x,l);

        a.merge(ask(y,l));
        long long t=0;
        for(int i=62;~i;i--)
            t=max(t,t^a.data[i]);
        printf("%lld\n",t);
    }        
}

