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
int n,q;
bool dp[61][1<<20];
inline int rd(int x){
    return (x>>1)|((x&1)<<(n-1));
}
int main(){
    q=read();n=read();
    dp[0][0]=1;
    int tmp=0;
    rep(i,1,3*n){
        tmp^=(1<<((i-1)%n));
        rep(j,0,(1<<n)-1){
            int x=tmp;
            rep(k,0,n-1)
                dp[i][j]|=dp[i-1][j^x],x=rd(x);
        }
    }
    while(q--){
        int a=0,b=0;
        rep(i,1,n){
            char c=gc();
            while(!isdigit(c))c=gc();
            a=(a<<1)|(c=='1');
        }
        rep(i,1,n){
            char c=gc();
            while(!isdigit(c))c=gc();
            b=(b<<1)|(c=='1');
        }
        if(a==0){
            prtl(0);
            continue;
        }
        rep(i,1,60){
            a^=b;
            if(dp[i][a]){
                prtl(i);
                break;
            }
            b=rd(b);
        }
    }
}