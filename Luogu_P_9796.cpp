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
#define M 100100
int p[M],v[M],k;
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int n,tt;
void exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {x = 1;y = 0;return;}
    exgcd(b, a % b,x,y);
    int Last_x = x;
    x = y;
    y = Last_x - a / b * y;
}
int main(){
    n=read();tt=n;
    linearSieve(100000);
    rep(i,1,k){
        int t=n;
        while(t%p[i]==0)t/=p[i];
        while(tt%p[i]==0)tt/=p[i];
        if(t==1){
            pf("NO\n");
            return 0;
        }
    }
    if(tt==n){
        pf("NO\n");
        return 0;
    }
    int a,b,x,y;
    rep(i,2,sqrt(n))
        if(n%i==0){
            if(__gcd(i,n/i)==1){
                a=i,b=n/i;
                break;
            }
        }
    exgcd(a,b,x,y);
    if(x<0){
        int sum=-(x-1)/b;
        x+=sum*b;y-=sum*a;
    }else{
        int sum=x/b+1;
        x-=sum*b;y+=sum*a;
    }
    pf("YES\n2\n%d %d\n%d %d\n",-x,n/a,a-y,n/b);
}