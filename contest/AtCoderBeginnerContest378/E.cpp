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
void print(ll x){
    if(x<0) return pc('-'),print(-x);
    if(x>9)print(x/10);
    pc(x%10+'0');
}
/*------------------------*/
int n,m;
int a[200200],s[200200];
ll ans=0;
template <int C>
struct FenwickTree{
    int data[C+1],c[C+1];
    FenwickTree()=default;
    int ask(int x){
        int ans=0;
        for(;x;x-=x&-x)ans+=c[x];
        return ans;
    }
    void add(int x,int d){
        for(;x<=C;x+=x&-x) c[x]+=d; 
    }
    void inti(void){
        for(int i=1;i<=C;i++) data[i]=c[i]=0;
    }
};
FenwickTree<200100> tr;
int main(){
    n=read();m=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        s[i]=(s[i-1]+a[i])%m;
    rep(i,1,n) 
        ans+=1ll*i*s[i];
    rep(i,1,n)
        ans-=1ll*(n-i+1)*s[i-1];
    tr.add(s[n]+1,1);
    per(i,0,n-1){
        ans+=1ll*m*tr.ask(s[i]);
        tr.add(s[i]+1,1);
    }
    print(ans);
}