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
int a,b,c,t;
#define p 998244353
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
    t=read();
    while(t--){
        a=read();b=read();c=read();
        if(a>b)swap(a,b);
        if(b!=c&&b+1!=c){
            prt(0);pc('\n');
            continue;
        }
        ll ans1=0,ans2=0;
        ans1+=qpow(10,a-1)*(5ll*qpow(10,a)%p-qpow(10,a-1)-4)%p;
        if(a<b&&a>1)(ans1+=qpow(10,a-2)*(5ll*qpow(10,a-1)%p-5+p)%p)%=p;
        ans2=(81ll*qpow(10,a+b-2)%p-ans1)%p;
        if(b==c)prt((ans2+p)%p),pc('\n');
        else prt((ans1+p)%p),pc('\n');
    }
}