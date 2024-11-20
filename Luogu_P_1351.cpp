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
#define M 400400
#define p 10007
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int w[M];
int sum,ans;
void dfs(int x,int fa){
    int sq=0,qs=0,maxx=0,maxn=0;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            (sq+=w[ver[i]])%=p;
            (qs+=w[ver[i]]*w[ver[i]]%p)%=p;
            if(w[maxx]<w[ver[i]])maxx=ver[i];
        }
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            if(w[maxn]<w[ver[i]]&&ver[i]!=maxx)maxn=ver[i];
    (sum+=(sq*sq%p+2*sq%p*w[fa]%p+p-qs)%p)%=p;
    if(maxx)ckmax(ans,w[maxx]*w[fa]);
    if(maxn)ckmax(ans,w[maxx]*w[maxn]);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            dfs(ver[i],x);
}
int n;
int main(){
    n=read();
    rep(i,1,n-1){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    rep(i,1,n)
        w[i]=read();
    dfs(1,0);
    prts(ans);prtl(sum);
}