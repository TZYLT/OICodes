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
template <unsigned C,class T>
struct FenwickTree{
    T c[C+1];
    T ask(unsigned x){T ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
    void add(unsigned x,T d){for(;x<=C;x+=x&-x) c[x]+=d;}
    void init(void){for(int i=0;i<=C;i++) c[i]=0;}
};
FenwickTree<300300,ll> tr;
int n,m;
pii a[300300];
ll sum;
vector<int> rg[300300];
pair<pii,int> qs[300300];
ll ans;
int main(){
    n=read();m=read();
    rep(i,1,n){
        int x=read();
        a[i]={x,i};
    }
    sort(a+1,a+1+n);
    rep(i,1,n){
        if(i>1&&i<n){
            if(a[i].fi-a[i-1].fi==a[i+1].fi-a[i].fi)
                rg[max(a[i].se,a[i-1].se)].push_back(min(a[i].se,a[i-1].se)),
                rg[max(a[i].se,a[i+1].se)].push_back(min(a[i].se,a[i+1].se));
            else if(a[i].fi-a[i-1].fi<a[i+1].fi-a[i].fi)
                rg[max(a[i].se,a[i-1].se)].push_back(min(a[i].se,a[i-1].se));
            else rg[max(a[i].se,a[i+1].se)].push_back(min(a[i].se,a[i+1].se));
        }else if(i==1){
            rg[max(a[i].se,a[i+1].se)].push_back(min(a[i].se,a[i+1].se));
        }else {
            rg[max(a[i].se,a[i-1].se)].push_back(min(a[i].se,a[i-1].se));
        }
    }
    rep(i,1,m){
        int x=read(),y=read();
        qs[i]={{y,x},i};
    }
    sort(qs+1,qs+1+m);
    rep(i,1,m){
        rep(j,qs[i-1].fi.fi+1,qs[i].fi.fi)
            for(auto c:rg[j])
                tr.add(c+1,1),sum++;
        ans+=1ll*(sum-tr.ask(qs[i].fi.se))*qs[i].se;
    }
    prtl(ans);
}