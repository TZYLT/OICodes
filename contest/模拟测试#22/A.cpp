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
#define int ll
#define p 998244353
int dp[200200][2],k,n[200200];
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int ans;
signed main(){
    k=read();
    rep(i,1,k)
        n[i]=read();
    rep(i,0,62){
        ms(dp,0);dp[0][0]=1;
        rep(j,1,k){
            int a=n[j]>>(i+1);
            int b=n[j]&((1ll<<i)-1);
            int x,y;//01
            if(n[j]&(1ll<<i)){
                x=(a+1)*qpow(2,i)%p;
                y=(a*qpow(2,i)%p+b+1)%p;
            }else{
                y=a*qpow(2,i)%p;
                x=(a*qpow(2,i)%p+b+1)%p;
            }
            //pf("%d %d|%d %d\n",a,b,x,y);
            (dp[j][0]+=x*dp[j-1][0]%p)%=p;
            (dp[j][1]+=y*dp[j-1][0]%p)%=p;
            (dp[j][0]+=y*dp[j-1][1]%p)%=p;
            (dp[j][1]+=x*dp[j-1][1]%p)%=p;
            //pf("%d %d\n",dp[i][0],dp[i][1]);
        }
        (ans+=dp[k][1]*qpow(2,i)%p)%=p;
        //prts(ans,'\n');
    }
    prt(ans);
}