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
#define p 1000000007
int n,m;
int dp[3030][3030][2];
int main(){
    n=read();m=read();
    dp[0][0][1]=1;
    rep(i,0,n)
        rep(j,0,i){
            (dp[i+1][j][1]+=1ll*j*dp[i][j][1]%p)%=p;
            (dp[i+1][j+1][0]+=1ll*(m-j)*dp[i][j][1]%p)%=p;
            (dp[i+1][j][1]+=1ll*j*dp[i][j][0]%p)%=p;
            (dp[i+1][j][0]+=1ll*(m-j)*dp[i][j][0]%p)%=p;
        }
    int ans=0;
    rep(i,0,n)
        (ans+=dp[n][i][1])%=p;
    prt(ans);
}