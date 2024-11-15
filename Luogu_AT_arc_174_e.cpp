#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(l);x>=(r);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
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
/*------Common-Factions------*/
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
#define p 998244353
#define M 500500
int inv[M],fac[M],ifac[M];
int n,k;
int a[M],s[M];
int f(int x,int y){return 1ll*fac[x]*ifac[x-y]%p;}
template <unsigned C,class T>
struct FenwickTree{
    T c[C+1];
    T ask(unsigned x){T ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
    void add(unsigned x,T d){for(;x<=C;x+=x&-x) c[x]+=d;}
    void init(void){for(int i=0;i<=C;i++) c[i]=0;}
};
FenwickTree<500500,int> bit;
pii id[M];
int ans1,ans2,ans3,ans4;
int main(){
    n=read();k=read();
    rep(i,1,k){
        id[i].fi=a[i]=read();
        id[i].se=i;
    }
    inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    fac[0]=ifac[0]=1;
    rep(i,1,n)
        fac[i]=1ll*fac[i-1]*i%p,
        ifac[i]=1ll*ifac[i-1]*inv[i]%p;
    ans1=f(n,k);
    ans2=f(n-1,k);

    rep(i,1,k){
        s[i]=i-bit.ask(a[i]);
        bit.add(a[i],1);
    }
    rep(i,1,k){
        (ans3+=1ll*(n+p-a[i]+p-s[i])*f(n-i,k-i))%=p;
        (ans4+=1ll*(n+p-a[i]+p-s[i])*f(n-i-1,k-i))%=p;
    }
    int ans=((ans1+p-ans2)%p+p-ans3+ans4)%p;
    sort(id+1,id+k+1);
    int j=1;
    rep(i,1,n){
        pii c=id[j];
        if(c.fi==i){
            (ans+=p-f(n-c.se-1,k-c.se))%=p;
            j++;
        }
        prtl(ans);
    }
}