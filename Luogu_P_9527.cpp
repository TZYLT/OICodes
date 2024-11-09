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
#define M 501000
int head[M],nextt[M],ver[M],cnt;
void add(int x,int y){
    ++cnt;
    ver[cnt]=y;
    nextt[cnt]=head[x];
    head[x]=cnt;
}
int n,p,q;
void ckmul(int &x,int y){x=1ll*x*y%p;}
int w[M],fa[M],tag[M][50];
void dfs(int x,int f){
    fa[x]=f;
    for(int i=head[x];i;i=nextt[i])
        if(ver[i]!=f)   
            dfs(ver[i],x);
}
int main(){
    n=read();p=read();
    rep(i,1,n-1){
        int x=read(),y=read();
        add(x,y);add(y,x);
    }
    rep(i,1,n)
        w[i]=read();
    dfs(1,0);
    rep(i,1,n)
        rep(j,0,45)
            tag[i][j]=1;
    q=read();
    while(q--){
        int op=read();
        if(op==1){
            int x=read(),d=read(),aw=read();
            while(d>=0&&x){
                if(x==1){
                    rep(i,0,d)
                        ckmul(tag[x][i],aw);
                    break;
                }else{
                    ckmul(tag[x][d],aw);
                    if(d>=1)ckmul(tag[x][d-1],aw);
                }
                x=fa[x];d--;
            }
        }else{
            int x=read(),d=0;
            int ans=w[x];
            while(d<=45&&x){
                ckmul(ans,tag[x][d]);
                x=fa[x];d++;
            }
            prt(ans);pc('\n');
        }
    }
}
