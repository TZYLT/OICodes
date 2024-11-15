#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(l);x>=(r);x--)
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
#define M 400400
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,sz[M];
ll k,s;
void dfs(int x,int fa){
    sz[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            sz[x]+=sz[ver[i]];
        }
    s+=sz[x];
}
pii si[M];
int tag[M],sum,w[M];
void dfs0(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs0(ver[i],x);
    if(!tag[x])w[x]=++sum;
}
void dfs1(int x,int fa){
    if(tag[x])w[x]=++sum;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs1(ver[i],x);
}
int main(){
    n=read();k=read();
    rep(i,1,n-1){
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    rep(i,1,n)
        si[i]={-sz[i],i};
    sort(si+1,si+1+n);
    if(k<n||k>s){
        pf("No");
        return 0;
    }
    rep(i,1,n)
        if(k+si[i].fi>=0){
            k+=si[i].fi;
            tag[si[i].se]=1;
        }
    pf("Yes\n");
    dfs0(1,0);dfs1(1,0);
    rep(i,1,n)
        prts(w[i]);
}