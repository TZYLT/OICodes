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
#define p 998244353
#define N 105
ll n,m;
ll a[105][2020];
ll s[105];
ll f[105][210],g[105][105];
ll ans=0;
int main(){
    n=read();m=read();
    rep(i,1,n)
        rep(j,1,m)
            (s[i]+=(a[i][j]=read()))%=p;
    rep(pos,1,m){
        msz(f);
        f[0][N]=1;
        rep(i,1,n)
            rep(j,N-n,N+n)
                f[i][j]=(f[i-1][j]+a[i][pos]*f[i-1][j-1]%p+(s[i]+p-a[i][pos])*f[i-1][j+1]%p)%p;
        rep(i,1,n)
            (ans+=f[n][N+i])%p;
    }
    g[0][0]=1;
    rep(i,1,n)
        rep(j,0,n)
            if(j!=0)g[i][j]=(g[i-1][j]+s[i]*g[i-1][j-1]%p)%p;
            else g[i][j]=g[i-1][j];
    ans=p-ans;
    rep(i,1,n)
        (ans+=g[n][i])%=p;
    prtl(ans);
}