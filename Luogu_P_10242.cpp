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
#define M 1<<20
#define N 1000100
int f[M];
int a[21][N],t[N];
int n,m;
int main(){
    n=read();m=read();
    rep(i,1,n)
        rep(j,1,m){
            a[i][j]=read();
            t[j]=(t[j]<<1)|(a[i][j]!=-1);
        }
            
    rep(i,1,n)
        rep(j,1,m)
                f[t[j]]+=a[i][j];
    rep(i,1,n)
        rep(j,1,m)
                f[t[j]^(1<<(i-1))]-=a[i][j];
    rep(i,0,n-1)
        rep(j,0,(1<<n)-1)
            if(j&(1<<i))
                f[j^(1<<i)]+=f[j];
    int ans=0;
    rep(i,0,(1<<n)-1)
        ckmax(ans,f[i]);
    prt(ans);


}