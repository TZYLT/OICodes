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
int n,q;
int a[500500],b[500500],st[500500];
int h;
int nxt[30][500500];
int main(){
    n=read();q=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        b[i]=read();
    rep(i,1,n){
        while(h&&(a[st[h]]==a[i]||b[i]>=b[st[h]]))
            nxt[0][st[h--]]=i;
        st[++h]=i;
    }
    rep(i,1,25)
        rep(j,1,n)
            nxt[i][j]=nxt[i-1][nxt[i-1][j]];
    while(q--){
        int l=read(),r=read();
        int ans=0;
        per(i,25,0)
            if(nxt[i][l]&&nxt[i][l]<=r){
                l=nxt[i][l];
                ans+=(1<<i);
            }
        prtl(ans+1);
    }
}