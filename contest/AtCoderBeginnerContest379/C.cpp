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
#define int long long
int n,m;
int x[200200],c[200200];
ll ans;
pair<int,int> it[200200];
signed main(){
    n=read();m=read();
    rep(i,1,m)
        x[i]=read();
    rep(i,1,m)
        c[i]=read();
    rep(i,1,m)
        it[i]={x[i],c[i]};
    sort(it+1,it+1+m);
    rep(i,1,m)
        x[i]=it[i].fi;
    rep(i,1,m)
        c[i]=it[i].se;  
    if(x[1]!=1){
        prt(-1);
        return 0;
    }
    int rem=0;
    rep(i,1,m-1){
        rem+=c[i];
        rem-=(x[i+1]-x[i]);
        if(rem<0){
            prt(-1);
            return 0;
        }
    }

    rem+=c[m];
    rem-=(n-x[m]+1);
    if(rem!=0){
        prt(-1);
        return 0;
    }

    rem=0;
    rem+=(n-x[m]+1);
    if(rem<=c[m]){ans+=1ll*rem*(rem-1)/2;rem=0;}
    else {ans+=1ll*c[m]*(2*rem-1-c[m])/2;rem-=c[m];}
    //prts(ans,' ');
    per(i,1,m-1){
        rem+=(x[i+1]-x[i]);
        if(rem<=c[i]){ans+=1ll*rem*(rem-1)/2;rem=0;}
        else {ans+=1ll*c[i]*(2*rem-1-c[i])/2;rem-=c[i];}
        //prts(ans,' ');
    }
    prt(ans);
}