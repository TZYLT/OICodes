#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define ll long long
#define ull unsigned long long
#define lf double
#define Lf long double
#define pii pair<int,int>
#define fi first
#define se second
#define pf printf
constexpr int inf=0x3f3f3f3f;
constexpr ll infll=0x3f3f3f3f3f3f3f3f;
/*------Common-Factions------*/
ll read(){
    ll x=0,f=1;char c=gc();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void prt(ll x){
    if(x<0) return pc('-'),prt(-x);
    if(x>9)prt(x/10);
    pc(x%10+'0');
}
void prts(ll x,char c){prt(x);pc(c);}
void prts(ll x){prt(x);pc(' ');}
void prts(ll x,string s){prt(x);for(auto c:s)pc(c);}
void prtl(ll x){prt(x);pc('\n');}
/*------------------------*/
#define M 600600
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int _size[M],dep[M],dis[M],hson[M],fa[M],top[M],sum[M];
void dfsI(int x,int ffa,int w){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    dis[x]=dis[ffa]+w;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=ffa){
            dfsI(ver[i],x,edge[i]);
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
pii rg[300300];
pii id[300300];
int n,m;
void dfs(int x,int ffa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=ffa){
            dfs(ver[i],x);
            sum[x]+=sum[ver[i]];
        }
}
bool ck(int lim){
    int maxxl=0,tot=0;
    msz(sum);
    per(i,1,m){
        if(id[i].fi<=lim)break;
        ckmax(maxxl,id[i].fi);
        int x=rg[id[i].se].fi,y=rg[id[i].se].se;
        sum[x]++;sum[y]++;sum[lca(x,y)]-=2;tot++;
    }
    dfs(1,0);
    int maxans=0;
    rep(i,1,n)
        if(sum[i]==tot)
            ckmax(maxans,dis[i]-dis[fa[i]]);
    return maxxl-maxans<=lim;
}
int sc(int l,int r){
    if(l==r)return l;
    int mid=(l+r)>>1;
    if(ck(mid))return sc(l,mid);
    else return sc(mid+1,r);
}
int main(){
    n=read();m=read();
    rep(i,1,n-1){
        int x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,z);
    }
    dfsI(1,0,0);
    dfsII(1,1);
    rep(i,1,m)
        rg[i]={read(),read()};
    rep(i,1,m){
        int x=rg[i].fi,y=rg[i].se;
        id[i]={dis[x]+dis[y]-2*dis[lca(x,y)],i};
    }
    sort(id+1,id+1+m);
    prtl(sc(0,1000000000));
}