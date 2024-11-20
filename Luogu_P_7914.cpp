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
}w
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
#define p 1000000007
string s;
int n,k;
ll dp[505][505][6];
bool ck(int i,int j){return (s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?');}
int main(){
    n=read();k=read();
    cin>>s;
    s=" "+s;
    rep(i,1,n)  
        dp[i][i-1][0]=1;
    rep(len,1,n)
        for(int l=1,r=len;r<=n;l++,r++){
            if(len<=k)dp[l][r][0]=dp[l][r-1][0]&&(s[r]=='*'||s[r]=='?');
            if(len>=2){
                if(ck(l,r))dp[l][r][1]=(dp[l+1][r-1][0]+dp[l+1][r-1][2]+dp[l+1][r-1][3]+dp[l+1][r-1][4])%p;
                rep(i,l,r-1){
                    dp[l][r][2]=(dp[l][r][2]+dp[l][i][3]*dp[i+1][r][0])%p;
                    dp[l][r][3]=(dp[l][r][3]+(dp[l][i][2]+dp[l][i][3])*dp[i+1][r][1])%p;
                    dp[l][r][4]=(dp[l][r][4]+(dp[l][i][4]+dp[l][i][5])*dp[i+1][r][1])%p;
                    dp[l][r][5]=(dp[l][r][5]+dp[l][i][4]*dp[i+1][r][0])%p;
                }
            }dp[l][r][5]=(dp[l][r][5]+dp[l][r][0])%p;
            dp[l][r][3]=(dp[l][r][3]+dp[l][r][1])%p;
        }
    prtl(dp[1][n][3]);
}