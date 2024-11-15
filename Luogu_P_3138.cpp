#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
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

int n,x[1010],y[1010];
vector<int> X,Y;
int sum[1010][1010];
int main(){
    n=read();
    rep(i,1,n){
        x[i]=read();
        y[i]=read();
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    rep(i,1,n){
        int tx=lower_bound(X.begin(),X.end(),x[i])-X.begin()+1;
        int ty=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin()+1;
        sum[tx][ty]++;
    }
    int cntx=X.size();
    int cnty=Y.size();
    rep(i,1,cntx)
        rep(j,1,cnty)
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int ans=inf;
    rep(i,1,cntx)
        rep(j,1,cnty)
            ckmin(ans,max({sum[i][j],sum[cntx][j]-sum[i][j],sum[i][cnty]-sum[i][j],sum[cntx][cnty]-sum[cntx][j]-sum[i][cnty]+sum[i][j]}));
    prtl(ans);
}