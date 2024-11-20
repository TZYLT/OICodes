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
#define mod 998244353
#define int ll
void exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {x = 1;y = 0;return;}
    exgcd(b, a % b,x,y);
    int Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}
int n,m,c,t;
int a[300300],b[300300];
signed main(){
    n=read();m=read();c=read();
    rep(i,1,n)
        a[i]=read()%mod;
    rep(i,1,m)
        b[i]=read()%mod;
    t=read();
    while(t--){
        int p=read(),q=read();
        int x,y,g=__gcd(p,q);
        if(c%g!=0){prtl(0);continue;}
        exgcd(p,q,x,y);
        x*=c/g;y*=c/g;
        p/=g;q/=g;
        y+=p*(x/q);x%=q;
        if(y>m){
            x+=q*ceil((lf)(y-m)/p);
            y-=p*ceil((lf)(y-m)/p);
        }
        if(x==0){
            x+=q;y-=p;
        }
        if(y==0){
            x-=q;y+=p;
        }
        if(x<0||y<0||x>n||y>m){prtl(0);continue;}
        int ans=0;
        for(;x<=n&&y>=1;x+=q,y-=p)
            (ans+=1ll*a[x]*b[y]%mod)%=mod;
        prtl(ans);
    }
}