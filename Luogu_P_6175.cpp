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
#define msu(x) memset(x,0x1f,sizeof(x))
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
int w[105][105],d[105][105];
int n,m;
int ans=inf;
int main(){
    n=read();m=read();
    msu(d);msu(w);
    rep(i,1,m){
        int x=read(),y=read(),z=read();
        ckmin(w[x][y],z);
        ckmin(w[y][x],z);
        ckmin(d[x][y],z);
        ckmin(d[y][x],z);
    }
    rep(k,1,n){
        rep(i,1,k-1)
            rep(j,1,i-1)
                if(i!=j)
                    ckmin(ans,d[i][j]+w[k][j]+w[i][k]);
        rep(i,1,n)
            rep(j,1,n)  
                ckmin(d[i][j],d[i][k]+d[k][j]);
    }
    if(ans<50010000)prtl(ans);
    else pf("No solution.");
}