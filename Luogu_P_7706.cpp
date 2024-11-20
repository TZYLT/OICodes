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
#define M 2002000
int l[M],r[M],a[M],b[M];
int n,m;
#define lc p<<1
#define rc p<<1|1

struct node{
    int maxx,minn,p,q,ph;
    friend node operator+(node x,node y){
        node ans;
        ans.maxx=max(x.maxx,y.maxx);
        ans.minn=min(x.minn,y.minn);
        ans.p=max(max(x.p,y.p),x.maxx-y.minn);
        ans.q=max(max(x.q,y.q),y.maxx-x.minn);
        ans.ph=max(max(x.ph,y.ph),max(x.p+y.maxx,y.q+x.maxx));
        return ans;
    }
}tr[M];

void build(int p,int li,int ri){
    //pf("[%d,%d]",li,ri);
    l[p]=li;r[p]=ri;
    if(li==ri){
        tr[p]={a[li],b[li],-inf,-inf,-inf};
        return;
    }
    int mid=(li+ri)>>1;
    build(lc,li,mid);
    build(rc,mid+1,ri);
    tr[p]=tr[lc]+tr[rc];
}
void cga(int p,int d,int x){
    if(l[p]==r[p]&&l[p]==d){
        tr[p].maxx=x;
        return ;
    }
    int mid=(l[p]+r[p])>>1;
    if(d<=mid)cga(lc,d,x);
    else cga(rc,d,x);
    tr[p]=tr[lc]+tr[rc];
}
void cgb(int p,int d,int x){
    if(l[p]==r[p]&&l[p]==d){
        tr[p].minn=x;
        return ;
    }
    int mid=(l[p]+r[p])>>1;
    if(d<=mid)cgb(lc,d,x);
    else cgb(rc,d,x);
    tr[p]=tr[lc]+tr[rc];
}
node ask(int p,int li,int ri){
    if(li<=l[p]&&r[p]<=ri)return tr[p];
    int mid=(l[p]+r[p])>>1;
    node nd={-inf,inf,-inf,-inf,-inf};
    if(li<=mid)nd=nd+ask(lc,li,ri);
    if(ri>mid)nd=nd+ask(rc,li,ri);
    return nd;
}
int main(){
    n=read();m=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        b[i]=read();   
    build(1,1,n);
    while(m--){
        int op=read(),x=read(),y=read();
        if(op==1)cga(1,x,y);
        else if(op==2)cgb(1,x,y);
        else prtl(ask(1,x,y).ph);
    } 
}