#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
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
/*------Common-Fictions------*/
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
/*------------------------*/
#define M 2001000
int fa[M],sz[M],dep[M];
pii st[M];int h;
int get(int x){
    if(fa[x]==x)return x;
    return get(fa[x]);
}
void merge(int x,int y){
    x=get(x);y=get(y);
    if(x==y)return ;
    if(dep[x]<dep[y])swap(x,y);
    st[++h]={y,dep[x]};
    sz[x]+=sz[y];
    ckmax(dep[x],dep[y]+1);
    fa[y]=x;
}
void undo(void){
    if(h==0)return;
    int x=st[h].first,dp=st[h].second;h--;
    sz[fa[x]]-=sz[x];
    dep[fa[x]]=dp;
    fa[x]=x;
}

int n,q;
int c[M];
unordered_map<ll,int> id;int cnt;
vector<int> eg[M];
vector<pii> edge;    
ll ans[M],sum[M];
ll shift(pii a){
    return 1ll*a.first*inf+a.second;
} 
int main(){
    n=read();q=read();
    rep(i,1,n)
        c[i]=read();
    rep(i,1,n)
        fa[i]=i,sz[i]=dep[i]=1;
    rep(i,2,n){
        int x=read();
        edge.push_back({i,x});
        if(c[i]==c[x]){merge(i,x);continue;}
        int a=min(c[i],c[x]),b=max(c[i],c[x]);
        if(id.count(shift({a,b}))==0)
            id[shift({a,b})]=++cnt;
        eg[id[shift({a,b})]].push_back(edge.size()-1);
    }
    h=0;
    rep(i,1,n)
        if(fa[i]==i)
            sum[c[i]]+=1ll*sz[i]*sz[i];
    
    for(auto c:id){
        int iid=c.second;
        ll ccp=c.first;
        pii cp={ccp/inf,ccp%inf};
        ans[iid]=sum[cp.fi]+sum[cp.se];
        for(auto i:eg[iid]){
            int x=get(edge[i].fi),y=get(edge[i].se);
            if(x!=y){
                ans[iid]+=2ll*sz[x]*sz[y];
                merge(x,y);
            }
        }
        while(h)undo();
    }
    while(q--){
        int a=read();
        int b=read();
        if(a>b)swap(a,b);
        if(id.count(shift({a,b}))==0) prt(sum[a]+sum[b]);
        else prt(ans[id[shift({a,b})]]);
        pc('\n');
    }
}