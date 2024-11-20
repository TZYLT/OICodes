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
#define M 2020
#define N 4040
int head[N],nextt[N],edge[N],ver[N],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
ll dp[M][M],sz[M],n,m;
void dfs(int x,int fa){
    sz[x]=1;
    dp[x][0]=dp[x][1]=0;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=fa){
            dfs(ver[i],x);
            sz[x]+=sz[ver[i]];
            per(j,0,min(m,sz[x])){
                if(dp[x][j]>=0)
                    dp[x][j]+=dp[ver[i]][0]+sz[ver[i]]*(n-m-sz[ver[i]])*edge[i];
                per(k,1,min((ll)j,sz[ver[i]]))
                    if(dp[x][j-k]>=0){
                        ll v=(k*(m-k)+(sz[ver[i]]-k)*(n-m-sz[ver[i]]+k))*edge[i];
                        ckmax(dp[x][j],dp[x][j-k]+dp[ver[i]][k]+v);
                    }
            }
        }
}
int main(){
    n=read();m=read();
    rep(i,1,n-1){
        int x=read(),y=read(),w=read();
        add(x,y,w);
        add(y,x,w);
    }
    msl(dp);
    dfs(1,0);
    prtl(dp[1][m]);
}