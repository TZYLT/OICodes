#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
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
/*------Common-Fictions------*/
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
/*------------------------*/
#define M 200200
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
ll dp[M],sum[M],dep[M];
ll c[M];
void dfsI(int x,int fa,int ds){
    sum[x]=c[x];
    dep[x]=dep[fa]+ds;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfsI(ver[i],x,edge[i]);
            sum[x]+=sum[ver[i]];
        }
}
void dfsII(int x,int fa){
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            ll z=edge[i];
            dp[ver[i]]=dp[x]+z*sum[1]-2*z*sum[ver[i]];
            dfsII(ver[i],x);
        }
}
int n;
int main(){
    n=read();
    rep(i,1,n)
        c[i]=read();
    rep(i,1,n-1){
        int x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,z);
    }
    
    dfsI(1,0,0);
    rep(i,2,n)
        dp[1]+=c[i]*(dep[i]);
    dfsII(1,0);
    ll ans=infll;
    rep(i,1,n)
        ckmin(ans,dp[i]);
    prt(ans); 
}