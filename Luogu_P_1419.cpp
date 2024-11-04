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

int n,S,T;
ll a[100100];
lf b[100100];
ll q[100100],t,h;
bool ck(lf x){
    t=1,h=0;
    rep(i,1,n)
        b[i]=(lf)a[i]-x;
    b[0]=0;
    rep(i,1,n)
        b[i]+=b[i-1];
    rep(i,1,n){
        while(t<=h&&q[t]<i-T)t++;
        if(i>=S){
            while(t<=h&&b[i-S]<b[q[h]])h--;
            q[++h]=i-S;
        }
        if(t<=h&&b[i]-b[q[t]]>=0)return 1;
    }
    return 0;
}
lf sc(lf l,lf r){
    if(r-l<1e-8)return l;
    lf mid=(l+r)/2.0;
    if(ck(mid))return sc(mid,r);
    else return sc(l,mid);
}
int main(){
    n=read();
    S=read();T=read();
    rep(i,1,n)
        a[i]=read();
    pf("%.3lf",sc(-10000000,10000000));
}