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
#define M 2001000
#define int long long
int n,m;
pii it[M];
int w[M],v[M];
int vis[M];
pii yh[M<<1];
int ans=0,minid;
struct nd{
    int free,lim,id;
    friend bool operator<(nd x,nd y){
        if(x.free!=y.free)
            return x.free<y.free;
        else if(x.lim!=y.lim)
            return x.lim>y.lim;
        else return 0;
    }
};
priority_queue<nd> q;
signed main(){
    //int st=clock();
    n=read();m=read();
    rep(i,1,n){
        int x=read(),y=read();
        it[i]={x,y};
        yh[i]={x,x-y};
    }
    //lim,off
    rep(i,1,m){
        w[i]=read();
        v[i]=read();
        yh[i+n]={w[i],v[i]};
    }
    sort(yh+1,yh+n+m+1);sort(it+1,it+n+1);
    rep(i,1,n)
        ans+=it[i].fi;
    minid=1;
    rep(i,1,n){
        rep(j,minid,n+m){
            if(yh[j].fi<=it[i].fi){
                minid=j;
                q.push({yh[j].se,yh[j].fi,j});
            }
            else break;
        }
        if(q.size()){
            nd x=q.top();q.pop();
            while(q.size()&&vis[x.id])x=q.top(),q.pop();
            ans-=x.free;
            vis[x.id]=1;
        }
    }
    prt(ans);
    //cerr<<clock()-st<<endl;
}