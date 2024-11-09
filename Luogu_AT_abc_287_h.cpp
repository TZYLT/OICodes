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
void print(ll x){
    if(x<0) return pc('-'),print(-x);
    if(x>9)print(x/10);
    pc(x%10+'0');
}
/*------------------------*/

bitset<2020> d[2020];
int n,m,q;
void upd(int x){
    rep(i,1,n)
        if(d[i][x])
            d[i]|=d[x];
}
int qs[10010][2],ans[10010];
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read();
        d[x][y]=1;
    }
    q=read();
    rep(i,1,q)
        qs[i][0]=read(),
        qs[i][1]=read();
    ms(ans,0x3f);
    rep(i,1,n){
        upd(i);
        rep(j,1,q)
            if(d[qs[j][0]][qs[j][1]])
                ckmin(ans[j],i);
    }
    rep(i,1,q)
        if(ans[i]<=n)print(max({ans[i],qs[i][0],qs[i][1]})),pc('\n');
        else print(-1),pc('\n');
}