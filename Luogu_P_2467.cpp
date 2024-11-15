#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define psb(x) push_back(x)
#define ppb() pop_back()
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
/*------Common-Factions------*/
template<class A,class B> inline void ckmax(A &x,B y){x=(x>(y)?x:(y));}
template<class A,class B> inline void ckmin(A &x,B y){x=(x<(y)?x:(y));}
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
void prts(ll x){prt(x);pc(' ');}
void prts(ll x,string s){prt(x);for(auto c:s)pc(c);}
void prtl(ll x){prt(x);pc('\n');}
/*------------------------*/
int n,p;
int dp[2][4500][2],sum[4500][2];
int main(){
    n=read();p=read();
    dp[1][1][0]=dp[1][1][1]=1;
    rep(i,2,n){
        rep(j,1,i)
            sum[j][0]=sum[j][1]=dp[i&1][j][0]=dp[i&1][j][1]=0;
        rep(j,1,i)
            sum[j][0]=(sum[j-1][0]+dp[i&1^1][j][0])%p,
            sum[j][1]=(sum[j-1][1]+dp[i&1^1][j][1])%p; 
        rep(j,1,i)
            dp[i&1][j][0]=sum[j-1][1],
            dp[i&1][j][1]=sum[i-1][0]+p-sum[j-1][0];
    }
    int ans=0;
    rep(i,1,n)
        (ans+=(dp[n&1][i][0]+dp[n&1][i][1])%p)%=p;
    prtl(ans);
}