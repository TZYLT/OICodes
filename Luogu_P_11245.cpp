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
#define ll __int128
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
void print(ll x){
    if(x<0) return pc('-'),print(-x);
    if(x>9)print(x/10);
    pc(x%10+'0');
}
/*------------------------*/
ll t,n,m,l,r;
int main(){
    t=read();
    while(t--){
        l=read();r=read();m=read();n=read();
        if(n==0||m==0)pf("Yes\n");
        else if(l==1)pf("No\n");
        else{
            if(n>m)swap(n,m);
            ll tt=floor((Lf)(n-1)/(l-1));
            ll p=n-(l-1)*tt;
            ll m0=tt*(l+1)+min(p-1,tt*(r-l));
            pf((m0<=m)?"Yes\n":"No\n");
        }
    }
}
