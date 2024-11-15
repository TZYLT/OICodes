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
int head[M],nextt[M],edge[M],ver[M],wi[M],cnt;
void add(int x,int y,int z,int w){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    wi[cnt]=w;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int low[M],dfn[M],st[M],h,tot,c;
int v[M];
void dfs(int x){
    low[x]=dfn[x]=++tot;
    st[++h]=x;
    for(int i=head[x];i;i=nextt[i]){
        if(!dfn[ver[i]]){
            dfs(ver[i]);
            low[x]=min(low[x],low[ver[i]]);
        }else 
            if(!v[ver[i]])
                low[x]=min(low[x],dfn[ver[i]]);
    }
    if(dfn[x]==low[x]){
        ++c;
        while(st[h]!=x)
            v[st[h--]]=c;
        v[x]=c;h--;
    }
}
namespace mp{
    int head[M],nextt[M],edge[M],ver[M],cnt;
    void add(int x,int y,int z){
        ++cnt;
        ver[cnt]=y;
        edge[cnt]=z;
        nextt[cnt]=head[x];
        head[x]=cnt;
    }
    int d[M],in[M],v[M],n;
    bool SPFA(int s){
        queue<int> q;
        memset(d,0xcf,sizeof d);
        memset(in,0,sizeof in);
        memset(v,0,sizeof v);
        q.push(s);v[s]=1;d[s]=0;
        while(q.size()){
            int x=q.front();q.pop();v[x]=0;
            for(int i=head[x];i;i=nextt[i]){
                int y=ver[i];
                if(d[y]<d[x]+edge[i]){
                    d[y]=d[x]+edge[i];
                    if(!v[y])q.push(y),in[y]=in[x]+1,v[y]=1;
                    if(in[y]>=n)return 0;
                }
            }
        }
        return 1;
    }
}
int n,m;
int sum[M],in[M];
int dp[M];
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read(),z=read();
        lf w;
        scanf("%lf",&w);
        add(x,y,z,10*w);
    }
    int s=read();
    dfs(s);
    rep(i,1,n)
        if(v[i])
            for(int j=head[i];j;j=nextt[j])
                if(v[ver[j]]!=v[i]&&v[ver[j]])
                    mp::add(v[i]+c,v[ver[j]],edge[j]);
    rep(i,1,n)
        if(v[i]){
            for(int j=head[i];j;j=nextt[j])
                if(v[ver[j]]==v[i]){
                    while(edge[j]){
                        sum[v[i]]+=edge[j];
                        edge[j]=wi[j]*edge[j]/10;
                    }
                }
        }
    rep(i,1,c)
        mp::add(i,i+c,sum[i]);
    
    mp::n=2*c;
    mp::SPFA(v[s]);
    int ans=-inf;
    rep(i,1,2*c)
        ckmax(ans,mp::d[i]);
    prtl(ans);
    
}