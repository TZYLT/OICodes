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
#define ld double
#define Ld long double
#define pii pair<int,int>
#define fi first
#define se second
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

int l,s,t,n;
int a[1010];
int now[1010];
bool tag[1010];
bool v[100100];
int dp[100100];
int main(){
    l=read();
    s=read();t=read();n=read();
    int dt=100;
    rep(i,1,n) a[i]=read();
    sort(a+1,a+1+n);
    rep(i,1,n) tag[i]=(a[i]<=l);
    if(a[1]<=100)dt=a[1];
    rep(i,2,n) a[i]-=(a[1]-dt);
    a[1]=dt;
    v[a[1]]=1;
    rep(i,2,n){
        if(a[i]-a[i-1]>100)now[i]=now[i-1]+100;
        else now[i]=now[i-1]+a[i]-a[i-1];
        if(tag[i])v[now[i]]=1;
    }
    ms(dp,0x3f);
    dp[0]=0;
    rep(i,1,100000)
        if(i-s>=0)
        rep(j,max(0,i-t),max(0,i-s))
            ckmin(dp[i],dp[j]+v[i]);
    print(dp[100000]);
}