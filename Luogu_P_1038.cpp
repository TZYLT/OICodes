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
#define int long long
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
#define M 100100
int head[M],nextt[M],edge[M],ver[M],cnt;
void add(int x,int y,int z){
    ++cnt;
    ver[cnt]=y;
    edge[cnt]=z;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int w[M],u[M],in[M];
int out[M];
int n,m;
queue<int> q;
signed main(){
    n=read();m=read();
    rep(i,1,n)
        w[i]=read(),u[i]=read();
    rep(i,1,m){
        int x,y,z;
        x=read();y=read();z=read();
        add(x,y,z);in[y]++;out[x]++;
    }
    rep(i,1,n)
        if(in[i]==0)
            q.push(i),w[i]+=u[i];
    while(q.size()){
        int x=q.front();q.pop();
        w[x]-=u[x];
        for(int i=head[x];i;i=nextt[i]){
            if(w[x]>0)w[ver[i]]+=w[x]*edge[i];
            in[ver[i]]--;
            if(in[ver[i]]==0)q.push(ver[i]);
        }
    }
    int cnt=0;
    rep(i,1,n)
        if(out[i]==0&&w[i]>0){
            cnt++;
            pf("%lld %lld\n",i,w[i]);
        }
    if(cnt==0)pf("NULL");
}