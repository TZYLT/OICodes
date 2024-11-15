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
#define int long long
#define M 200200
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int d[M],v[M],tag[M],id[M],tot;
void dfs(int x,int fa,int w,int idd){
    d[x]=d[fa]+w;v[x]=1;id[x]=idd;
    
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            if(v[ver[i]]){
                if(d[x]+edge[i]!=d[ver[i]])
                    tag[idd]=1;
            }else dfs(ver[i],x,edge[i],idd);
        }
}
int n,m,q;
signed main(){
    n=read();m=read();q=read();
    rep(i,1,m){
        int x=read(),y=read(),z=read();
        add(x,y,z);
        add(y,x,-z);
    }
    rep(i,1,n)  
        if(!v[i])
            dfs(i,0,0,++tot);
    while(q--){
        int x=read(),y=read();
        if(id[x]!=id[y]){
            pf("nan\n");
            continue;
        }
        if(tag[id[x]]){
            pf("inf\n");
            continue;
        }
        prtl(d[y]-d[x]);
    }
}