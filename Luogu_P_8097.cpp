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
/*------------------------*/
#define M 500100
int n,q;
vector<pii> eg;
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int v[M];
int qs[M],opt[M];
int ans[M],adv[M],advg[M];

void dfs(int x,int id){
    ans[x]=id;
    v[x]=1;
    for(int i=head[x];i;i=nextt[i])
        if(!v[ver[i]])
            dfs(ver[i],id);
}

int main(){
    n=read();q=read();
    rep(i,1,q){
        char c=gc();
        while(c!='D'&&c!='A'&&c!='R')
            c=gc();
        if(c=='D'){
            int x=read();
            qs[i]=1;
            opt[i]=x;
            adv[x]=1;
        }else if(c=='A'){
            int x=read();
            int y=read();
            qs[i]=2;
            eg.push_back({x,y});
        }else if(c=='R'){
            qs[i]=3;
            opt[i]=read()-1;
            advg[opt[i]]=1;
        }
    }

    rep(i,0,eg.size()-1)
        if(!advg[i])
            add(eg[i].fi,eg[i].se),add(eg[i].se,eg[i].fi);
    rep(i,1,n)
        if(!v[i]&&!adv[i])
            dfs(i,q);

    per(i,1,q){
        if(qs[i]==1){
            if(!v[opt[i]])
                dfs(opt[i],i-1);
        }else if(qs[i]==3){
            int x=eg[opt[i]].fi,y=eg[opt[i]].se;
            add(x,y);
            add(y,x);
            if(v[x]^v[y])
                dfs(v[x]?y:x,i-1);
        }
    }
    rep(i,1,n)
        pf("%d\n",ans[i]);
}