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
int fac[10001000],t,n,r;
int v[10001000],p[10001000],k;
int sum[10001000],isv[10001000],inv[10001000];
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int main(){
    t=read();r=read();
    fac[0]=1;
    linearSieve(10000000);
    rep(i,1,10000000)
        if(i==r)fac[i]=fac[i-1];
        else fac[i]=1ll*fac[i-1]*i%r;
    inv[1]=1;
    for(int i=2;i<=10000000;++i)
        inv[i]=(long long)(r-r/i)*inv[r%i]%r;
    sum[0]=1;isv[0]=1;
    rep(i,1,10000000)
        if(!v[i]&&i!=r){
            sum[i]=1ll*sum[i-1]*(i-1)%r;
            isv[i]=1ll*isv[i-1]*inv[i]%r;
        }
        else if(!v[i]&&i==r){
            sum[i]=1ll*sum[i-1]*(i-1)%r;
            isv[i]=isv[i-1];
        }else{
            sum[i]=sum[i-1];
            isv[i]=isv[i-1];
        }

    while(t--){
        int n=read(),m=read();
        if(m>=r||n<r){
            prtl(1ll*fac[n]*sum[m]%r*isv[m]%r);
        }else if(n>=r){
            prtl(0);
        }

    }
}