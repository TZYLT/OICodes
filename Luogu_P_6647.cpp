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
ll n,k,a[1001000];
ll dp[1001000];
template <int C>
struct SegmentTree{
    ll sum[4*C+1];
    void change(int p,int l,int r,int x,ll d){
        if(l>r)return;
        if(x==l&&x==r)
            return sum[p]=d,void(); 
        
        int mid=(l+r)/2;
        if(x<=mid)change(p*2,l,mid,x,d);
        if(x>mid)change(p*2+1,mid+1,r,x,d);
        sum[p]=max(sum[p*2],sum[p*2+1]);
    }
    ll ask(int p,int l,int r,int li,int ri){
        if(l>r)return -infll;
        if(li<=l&&ri>=r) return sum[p];
        int mid=(l+r)/2;
        ll v=-infll;
        if(li<=mid)ckmax(v,ask(p*2,l,mid,li,ri));
        if(ri>mid)ckmax(v,ask(p*2+1,mid+1,r,li,ri));
        return v;
    } 
};
SegmentTree<1001000> s,f,fm;
int main(){
    n=read();k=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        s.change(1,1,n,i,a[i]);
    rep(i,1,n){
        int l=i-k,r=((i-1)/k)*k;
        if(l>r)continue;
        dp[i]=max(fm.ask(1,0,n,max(l,0),max(r,0))
            ,f.ask(1,0,n,max(l,0),max(r,0))+s.ask(1,1,n,r+1,i));
        f.change(1,0,n,i,dp[i]);
        fm.change(1,0,n,i,dp[i]+s.ask(1,1,n,i+1,min(r+k,n)));
    }
    prtl(dp[n]);
}