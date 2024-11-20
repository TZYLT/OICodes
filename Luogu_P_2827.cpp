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
#define int ll
ll A[100100];
queue<ll> a,b,c;
int n,m,q,u,v,t;
ll dt;
vector<int> ans;
signed main(){
    n=read();m=read();q=read();u=read();v=read();t=read();
    rep(i,1,n)
        A[i]=read();
    sort(A+1,A+1+n);
    per(i,1,n)
        a.push(A[i]);
    rep(i,1,m){
        pii pt=max({(pii){(a.size()?a.front():-inf),1}
                    ,(pii){(b.size()?b.front():-inf),2}
                    ,(pii){(c.size()?c.front():-inf),3}});
        if(pt.se==1)a.pop();
        if(pt.se==2)b.pop();
        if(pt.se==3)c.pop();
        ll now=pt.fi+dt;
        ans.push_back(now);
        ll l=now*u/v,r=now-l;
        b.push(l-dt-q);
        c.push(r-dt-q);
        dt+=q;
    }
    for(int i=t;i<=m;i+=t)
        prts(ans[i-1]);
    ans.clear();
    rep(i,1,n+m){
        pii pt=max({(pii){(a.size()?a.front():-inf),1}
                    ,(pii){(b.size()?b.front():-inf),2}
                    ,(pii){(c.size()?c.front():-inf),3}});
        if(pt.se==1)a.pop();
        if(pt.se==2)b.pop();
        if(pt.se==3)c.pop();
        ll now=pt.fi+dt;
        ans.push_back(now);
    }
    pc('\n');
    for(int i=t;i<=m+n;i+=t)
        prts(ans[i-1]);
}