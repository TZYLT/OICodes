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
int f[25];
bool merge(int x){
    for(int i=24;~i;i--)
        if(x>>i&1){
            if(!f[i])return f[i]=x,1;
            else x^=f[i];
        }
    return 0;
}
int n,k;
int gr[1<<20];
int bs[25];
int main(){
    n=read();k=read();
    int cnt=0;
    rep(i,0,(1<<n)-1)
        if(__builtin_popcount(i)==k)
            if(merge(i))bs[cnt++]=i;
    if(cnt<n){
        prts(0,'\n');
        return 0;
    }else prts(1,'\n');
    rep(i,0,(1<<n)-1){
        int g=(i^(i>>1));
        int ans=0;
        rep(j,0,n-1)
            if((g>>j)&1)
                ans^=bs[j];
        prts(ans,' ');
    }
}