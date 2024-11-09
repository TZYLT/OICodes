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
#define M 200100
#define p 1000000007
int f[M],g[M],c[M],n,ans;
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
inline void mul(int &x,int y){x=1ll*x*y%p;}
void dfs(int x,int fa){
    f[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            int t=1;
            for(int j=head[ver[i]];j;j=nextt[j])
                if(ver[j]!=x)
                    if(c[x]==c[ver[j]])
                        mul(t,f[ver[j]]+1);
                
            if(c[x]==c[ver[i]])
                (t+=f[ver[i]])%=p;
            mul(f[x],t);
        }
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa)
            mul(g[c[ver[i]]],f[ver[i]]+1);
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            ans=(ans+g[c[ver[i]]]-1)%p;
            g[c[ver[i]]]=1;
        }
        
}
int main(){
    n=read();
    rep(i,1,n)
        c[i]=read();
    rep(i,1,n-1){
        int x=read();int y=read();
        add(x,y);add(y,x);
    }
    add(0,1);
    rep(i,0,n)
        g[i]=1;
    dfs(0,0);
    prt(ans);
}