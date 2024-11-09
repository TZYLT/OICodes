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
#define p 998244353
int n,m,k,x;
int a[2020],inv[2020],ifac[2020],fac[2020];
int C(int x,int y){return 1ll*fac[x]*ifac[y]%p*ifac[x-y]%p;}
long long qpow(long long a,long long k){
    
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    n=read();m=read();k=read();x=read();
    rep(i,1,n)
        a[i]=read();
    fac[0]=ifac[0]=inv[1]=1;
    rep(i,2,k)
        inv[i]=1ll*(p-p/i)*inv[p%i]%p;
    rep(i,1,k)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    int ans=0;
    rep(i,1,m){
        int c=0;
        rep(j,1,n)
            c+=(a[j]>=i);
        rep(pp,0,k){
            int nc=max(c+pp-k,min(c+pp,n-x+1));
            (ans+=1ll*C(k,pp)*qpow(i-1,k-pp)%p*qpow(m-i+1,pp)%p*nc%p)%=p;
        }
    }
    prt(ans);
}