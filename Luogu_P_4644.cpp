#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define pc(x) putchar(x);
#define ll long long
#define ull unsigned long long
#define ld double
#define Ld long double
#define pii pair<int,int>
#define fi first
#define se second
constexpr int inf=0x3f3f3f3f;
constexpr ll infll=0x3f3f3f3f3f3f3f3f;

ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }while(isdigit(c)){
        x=x*10+(c^48);
        c=getchar();
    }return x*f;
}
void print(ll x){
    if(x<0){
        putchar('-');
        return print(-x);
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
/*------------------------*/
#define M 100100
ll dp[M],sum[M];
int n,l,r;
pair<pii,ll> qs[M];
void add(int x,ll d){
    x=100000-x;
    for(;x<=100000;x+=x&-x)
        ckmin(sum[x],d);
}
ll ask(int x){
    ll ans=infll;
    x=100000-x;
    for(;x;x-=x&-x)
        ckmin(ans,sum[x]);
    return ans;
}
ll ans=infll;
int main(){
    n=read();l=read();r=read();
    rep(i,1,n)
        qs[i].fi.se=read(),qs[i].fi.fi=read(),qs[i].se=read();
    sort(qs+1,qs+1+n);
    ms(dp,0x3f);
    ms(sum,0x3f);
    rep(i,1,n){
        if(qs[i].fi.se>l)
            dp[i]=ask(qs[i].fi.se-1)+qs[i].se;
        else dp[i]=qs[i].se;
        if(qs[i].fi.fi>=r)ckmin(ans,dp[i]);
        add(qs[i].fi.fi,dp[i]);
    }
    if(ans>=infll)print(-1);
    else print(ans);

}