#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define psb(x) push_back(x)
#define ppb() pop_back()
#define ll long long
#define ull unsigned long long
#define lf double
#define Lf long double
#define pii pair<int,int>
#define fi first
#define se second
#define pf printf
#define ckc cout<<"sb"<<endl
constexpr int inf=0x3f3f3f3f;
constexpr ll infll=0x3f3f3f3f3f3f3f3f;
/*------Common-Factions------*/
template<class A,class B> inline void ckmax(A &x,B y){x=(x>(y)?x:(y));}
template<class A,class B> inline void ckmin(A &x,B y){x=(x<(y)?x:(y));}
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
#define int ll
#define M 1000600
int head[M],nextt[M],edge[M],tag[M],ver[M],cnt=1;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
pii merge(pii x,pii y){
    if(x.fi>y.fi){
        int ans=-infll;
        if(x.se!=x.fi)ckmax(ans,x.se);
        if(y.fi!=x.fi)ckmax(ans,y.fi);
        if(y.se!=x.fi)ckmax(ans,y.se);
        return {x.fi,ans};
    } else {
        int ans=-infll;
        if(y.se!=y.fi)ckmax(ans,y.se);
        if(x.fi!=y.fi)ckmax(ans,x.fi);
        if(x.se!=y.fi)ckmax(ans,x.se);
        return {y.fi,ans};
    }
}
vector<pair<pii,pii> > eg;
template <int C>
struct DisjointSet{
    int fa[C];
    DisjointSet<C>& init(void){
        for(int i=0;i<C;i++)
                fa[i]=i; 
            return *this;
    }
    int get(int x){
        if(x==fa[x]) return x;
        return fa[x]=get(fa[x]);
    } 
    void merge(int x,int y){
        fa[get(x)]=get(y);
    }
};
DisjointSet<M> st;
int _size[M],dep[M],hson[M],hw[M],fa[M],top[M],w[M],dfn[M],cc;
void dfsI(int x,int ffa,int wi){
    int s=-1;
    _size[x]=1;fa[x]=ffa;
    dep[x]=dep[ffa]+1;
    hw[x]=wi;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=ffa&&tag[i]){
            dfsI(ver[i],x,edge[i]);
            _size[x]+=_size[ver[i]];
            if(s<_size[ver[i]])s=_size[ver[i]],hson[x]=ver[i];
        }
}
void dfsII(int x,int tp){
    top[x]=tp;
    dfn[x]=++cc;
    w[dfn[x]]=hw[x];
    if(!hson[x])return;
    dfsII(hson[x],tp);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa[x]&&ver[i]!=hson[x]&&tag[i])
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
int l[M],r[M];
pii maxx[M];
#define lc (p<<1)
#define rc (p<<1|1)
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]={w[li],-infll};
        return;
    }
    int mid=(li+ri)>>1;
    build(lc,li,mid);
    build(rc,mid+1,ri);
    maxx[p]=merge(maxx[lc],maxx[rc]);
}
pii ask(int p,int li,int ri){
    if(li>ri)return {-infll,-infll};
    if(li<=l[p]&&r[p]<=ri)
        return maxx[p];
    int mid=(l[p]+r[p])>>1;
    pii ans={-infll,-infll};
    if(li<=mid) ans=merge(ans,ask(lc,li,ri));
    if(ri>mid) ans=merge(ans,ask(rc,li,ri));
    return ans;
}
pii query(int x,int y){
    pii ans={-infll,-infll};
    int t=lca(x,y);
    while(dep[t]<dep[top[x]]){
        pii tp=ask(1,dfn[top[x]],dfn[x]);
        ans=merge(ans,tp);
        x=fa[top[x]];
    }
    pii tp=ask(1,dfn[t]+1,dfn[x]);
    ans=merge(ans,tp);

    while(dep[t]<dep[top[y]]){
        pii tp=ask(1,dfn[top[y]],dfn[y]);
        ans=merge(ans,tp);
        y=fa[top[y]];
    }
    tp=ask(1,dfn[t]+1,dfn[y]);
    ans=merge(ans,tp);

    return ans;
}
int n,m;
ll Ans=infll,ans=0;
void kruskal(void){
    sort(eg.begin(),eg.end());
    st.init();
    for(auto c:eg){
        int w=c.fi.fi,x=c.se.fi,y=c.se.se;
        if(st.get(x)!=st.get(y)){
            st.merge(x,y);
            tag[c.fi.se]=tag[c.fi.se^1]=1;
            ans+=w;
        }
    }
}
signed main(){
    n=read();m=read();
    int tot=0;
    rep(i,1,m){
        int x=read(),y=read(),z=read();
        if(x==y){tot++;continue;}
        add(x,y,z);add(y,x,z);
        eg.push_back({{z,cnt},{x,y}});
    }
    kruskal();
    dfsI(1,0,0);
    dfsII(1,1);
    build(1,1,n);
    rep(i,1,n)
        for(int j=head[i];j;j=nextt[j])
            if(!tag[j]&&i<ver[j]){
                pii t=query(i,ver[j]);
                int lst;
                if(t.fi!=edge[j])lst=t.fi;
                else lst=t.se;
                ckmin(Ans,ans-lst+edge[j]);
            }
    prtl(Ans);
}