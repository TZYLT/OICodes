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
void prt(__int128 x){
    if(x<0) return pc('-'),prt(-x);
    if(x>9)prt(x/10);
    pc(x%10+'0');
}
/*------------------------*/

template <int C>
struct FenwickTree{
    __int128 c[C+1];
    FenwickTree()=default;
    __int128 ask(int x){
        __int128 ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,__int128 d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
};
FenwickTree<1001000> sum;
int a[1001000],st[1001000],n;
__int128 ans;
int main(){
    n=read();
    rep(i,1,n)
        st[i]=a[i]=read();
    sort(st+1,st+1+n);
    int cnt=unique(st+1,st+1+n)-st;
    rep(i,1,n)
        a[i]=lower_bound(st+1,st+1+cnt,a[i])-st;
    
    per(i,1,n){
        ans+=sum.ask(a[i]-1)*i;
        sum.add(a[i],n-i+1);
    }
    prt(ans);
}