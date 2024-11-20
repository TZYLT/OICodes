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
#define p 998244353
int n;
int a[1001000];
int b[1001000];
int f[1001000];
int main(){
    n=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        b[a[i]]=i;
    rep(i,1,n)
        if(a[i]!=b[i]&&a[i]!=0&&b[i]!=0){
            prtl(0);
            return 0;
        }
    rep(i,1,n){
        if(a[i]&&!b[i])
            b[i]=a[i];
        if(!a[i]&&b[i])
            a[i]=b[i];
    }
    int ans=1,cnt=0;
    rep(i,1,n)cnt+=(a[i]==0);
    f[0]=1;
    f[1]=1;f[2]=2;
    rep(i,3,cnt)
        f[i]=(1ll*(i-1)*f[i-2]%p+f[i-1])%p;
    prtl(f[cnt]);
}