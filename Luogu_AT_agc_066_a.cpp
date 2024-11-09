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
int a[505][505],ans[505][505],sum;
int n,d;
int main(){
    n=read();d=read();
    rep(i,1,n)
        rep(j,1,n)
            ans[i][j]=a[i][j]=read();
    //Case1
    rep(i,1,n)
        rep(j,1,n){
            int rem=(ans[i][j]%(2*d)+(2*d))%(2*d);
            if((i+j)&1){
                if(rem<=d) ans[i][j]-=rem,sum+=rem;
                else ans[i][j]+=(2*d-rem),sum+=(2*d-rem);
            }else{
                if(rem<=d) ans[i][j]+=d-rem,sum+=d-rem;
                else ans[i][j]-=rem-d,sum+=rem-d;
            }
        }
    if(sum<=d*n*n/2){
        rep(i,1,n){
            rep(j,1,n)
                prt(ans[i][j]),pc(' ');
            pc('\n');
        }
        return 0;
    }
    //Case2
    rep(i,1,n)
        rep(j,1,n)
            ans[i][j]=a[i][j];sum=0;
    rep(i,1,n)
        rep(j,1,n){
            int rem=(ans[i][j]%(2*d)+(2*d))%(2*d);
            if(((i+j)&1)==0){
                if(rem<=d) ans[i][j]-=rem,sum+=rem;
                else ans[i][j]+=(2*d-rem),sum+=(2*d-rem);
            }else{
                if(rem<=d) ans[i][j]+=d-rem,sum+=d-rem;
                else ans[i][j]-=rem-d,sum+=rem-d;
            }
        }
    rep(i,1,n){
        rep(j,1,n)
            prt(ans[i][j]),pc(' ');
        pc('\n');
    }
}