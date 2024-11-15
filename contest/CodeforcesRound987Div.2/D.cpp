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
/*------Mommon-Factions------*/
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
#define M 500500
int t,n,a[M],ans[M];
int l[4*M],r[4*M];
pii maxx[4*M],minn[4*M];
void build(int p,int li,int ri){
    l[p]=li;r[p]=ri;
    if(li==ri){
        maxx[p]={a[li],-li};
        minn[p]={a[li],li};
        return;
    }
    int mid=(li+ri)/2;
    build(p*2,li,mid);
    build(p*2+1,mid+1,ri);
    maxx[p]=max(maxx[p*2],maxx[p*2+1]);
    minn[p]=min(minn[p*2],minn[p*2+1]);
}
pii askmax(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return maxx[p];
    int mid=(l[p]+r[p])/2;
    pii v={-inf,-inf};
    if(li<=mid)ckmax(v,askmax(p*2,li,ri));
    if(ri>mid)ckmax(v,askmax(p*2+1,li,ri));
    return v;
} 
pii askmin(int p,int li,int ri){
    if(li<=l[p]&&ri>=r[p]) return minn[p];
    int mid=(l[p]+r[p])/2;
    pii v={inf,inf};
    if(li<=mid)ckmin(v,askmin(p*2,li,ri));
    if(ri>mid)ckmin(v,askmin(p*2+1,li,ri));
    return v;
} 
map<int,int> st;
void sc(int l,int r){
    if(l>=r)return;
    pii ps=askmax(1,l,r);
    int as=0;
    if((*st.begin()).first>=ps.first){
        rep(i,-ps.se,r)
            ckmax(ans[i],ps.fi);
        as=ps.fi;
    }else{
        int t=(*(st.lower_bound(ps.fi)--)).second;
        rep(i,-ps.se,r)
            ckmax(ans[i],t);
        ps.fi=t;
    }
    int minn=askmin(1,-ps.se,r).first;
    st[minn]=as;
    sc(l,-ps.se-1);
}
int main(){
    t=read();
    while(t--){
        n=read();
        rep(i,1,n)
            ans[i]=a[i]=read();
        build(1,1,n);
        sc(1,n);
        rep(i,1,n)
            prts(ans[i]);
        pc('\n');
    }
}