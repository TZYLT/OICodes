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
#define N 100100
#define int long long
int v[N],d[N];
int dp[2][N];
int n,k,m;
void dijkstra(int s){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[0]=0;
    rep(i,1,m-1){
        int x=-1;
        rep(j,0,m-1)
            if(!v[j]&&(x==-1||d[j]<d[x]))x=j;
        v[x]=1;
        rep(j,0,m-1){
            int z=dp[k&1][j];
            ckmin(d[(x+j)%m],d[x]+z);
        }
    }
}

vector<pii> it[10010];

signed main(){
    n=read();k=read();m=read();
    rep(i,1,n){
        int x=read(),m=read(),w=read();
        it[x].push_back({m,w});
    }
    rep(j,1,m-1)
        dp[0][j]=infll;
    rep(i,1,k){
        rep(j,0,m-1)
            dp[i&1][j]=infll;
        rep(j,0,m-1)
            for(pii c:it[i])
                ckmin(dp[i&1][(j+c.fi)%m],dp[i&1^1][j]+c.se);
    }
    dijkstra(0);
    rep(i,0,m-1)
        if(d[i]!=infll)
            prtl(d[i]);
        else prtl(-1);
}