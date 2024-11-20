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
#define M 500500
int fa[M],sz[M],maxx[M],minn[M];
int n,q;
int cl[M],sum[M];
void init(void){
    for(int i=0;i<=n;i++)
            fa[i]=i,sz[i]=1,maxx[i]=minn[i]=i;
}
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
} 
void merge(int x,int y){
    x=get(x);y=get(y);
    if(x==y)return;
    ckmax(maxx[y],maxx[x]);
    ckmin(minn[y],minn[x]);
    sz[y]+=sz[x];
    fa[x]=y;
}

int main(){
    n=read();q=read();
    rep(i,1,n)
        cl[i]=i,sum[i]=1;
    init();
    while(q--){
        int op=read();
        if(op==1){
            int x=read(),c=read();
            int fx=get(x);
            sum[cl[fx]]-=sz[fx];
            sum[c]+=sz[fx];
            cl[fx]=c;
            if(minn[fx]>1){
                int rt=get(minn[fx]-1);
                if(cl[rt]==c)
                    merge(fx,rt);
            }
            if(maxx[fx]<n){
                int rt=get(maxx[fx]+1);
                if(cl[rt]==c)
                    merge(fx,rt);
            }    
        }else{
            int c=read();
            prtl(sum[c]);
        }
    }
}