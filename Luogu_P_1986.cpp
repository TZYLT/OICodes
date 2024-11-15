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
int n,m;
pair<pii,int> rg[5050];
int t[300300];
int ans;
int main(){
    n=read();m=read();
    rep(i,1,m){
        int x=read(),y=read(),z=read();
        rg[i]={{y,-x},z};
    }
    sort(rg+1,rg+1+m);
    rep(i,1,m){
        int cnt=0;
        rep(j,-rg[i].fi.se,rg[i].fi.fi)
            cnt+=t[j];
        if(cnt<rg[i].se){
            per(j,-rg[i].fi.se,rg[i].fi.fi)
                if(cnt<rg[i].se&&!t[j]){
                    t[j]=1;cnt++;ans++;
                }
        }
    }
    prt(ans);
    
}