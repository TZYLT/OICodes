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
#define M 20020
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int dep[M],fa[M];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs(ver[i],x);
}
pii dt[M];
int n;
int w[M];
int main(){
    n=read();
    fa[1]=1;
    rep(i,2,n){
        int x=read();
        fa[i]=x;
        add(x,i);
        add(i,x);
    }
    dfs(1,0);
    rep(i,1,n)
        dt[i]={-dep[i],i};
    sort(dt+1,dt+1+n);
    int ans=0;
    rep(i,1,n){
        int x=dt[i].se;
        if(w[x]>=1||w[fa[x]]>=2||w[fa[fa[x]]]>=3)
            continue;
        ans++;
        x=fa[fa[x]];
        w[x]=3;ckmax(w[fa[x]],2);ckmax(w[fa[fa[x]]],1);
    }
    prtl(ans);
}