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
ll n,k,a[200200],dp[200200][2],cnt[200200][2];
ll ans;
//0-red 1-blue
bool check(ll x){
    ms(dp,0xcf);ms(cnt,0);
    dp[1][0]=x;dp[1][1]=0;
    cnt[1][0]=1;cnt[1][1]=0;
    rep(i,2,n){
        if(dp[i-1][0]<=dp[i-1][1]+a[i]){
            dp[i][0]=dp[i-1][1]+a[i]+x;
            cnt[i][0]=cnt[i-1][1]+1;
        }else {
            dp[i][0]=dp[i-1][0]+x;
            cnt[i][0]=cnt[i-1][0]+1;
        }
        if(dp[i-1][0]+a[i]<=dp[i-1][1]){
            dp[i][1]=dp[i-1][1];
            cnt[i][1]=cnt[i-1][1];
        }else{
            dp[i][1]=dp[i-1][0]+a[i];
            cnt[i][1]=cnt[i-1][0];
        }
    }
    return dp[n][1]>dp[n][0]?(cnt[n][1]<=k):(cnt[n][0]<=k);
}
void sc(ll l,ll r){
    if(l>r)return ;
    ll mid=(l+r)>>1;
    if(check(mid)){
        ans=max(dp[n][1],dp[n][0])-k*mid;
        return sc(mid+1,r),void();
    }
    else return sc(l,mid-1),void();
}
int main(){
    n=read();k=read();
    rep(i,2,n)
        a[i]=read();
    sc(-2e10,2e10);
    prt(ans);
}