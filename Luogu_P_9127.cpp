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
ll n,a[505];
pair<ll,pair<ll,ll>> rg[255000];
ll cnt;
ll ans[505];
int main(){
    n=read();
    rep(i,1,n)
        a[i]=read()+a[i-1];
    rep(i,1,n)
        rep(j,i,n)
            rg[++cnt]={a[j]-a[i-1],{i,j}};
    sort(rg+1,rg+1+cnt);
    msu(ans);
    rep(i,1,cnt-1){
        ll dt=abs(rg[i].fi-rg[i+1].fi);
        pair<ll,ll> l=rg[i].se,r=rg[i+1].se;
        if(l>r)swap(l,r);
        if(l.se<r.fi){
            rep(i,l.fi,l.se)
                ckmin(ans[i],dt);
            rep(i,r.fi,r.se)
                ckmin(ans[i],dt);
        }else if(l.se<r.se){
            rep(i,l.fi,r.fi-1)
                ckmin(ans[i],dt);
            rep(i,l.se+1,r.se)
                ckmin(ans[i],dt);
        }else{
            rep(i,l.fi,r.fi-1)
                ckmin(ans[i],dt);
            rep(i,r.se+1,l.se)
                ckmin(ans[i],dt);
        }
    }
    rep(i,1,n)
        prtl(ans[i]);
}