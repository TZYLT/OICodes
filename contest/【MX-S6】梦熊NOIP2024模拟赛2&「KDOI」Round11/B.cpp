#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmod(x,y) x=(x>=(y)?x-y:(x))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define msz(x) memset(x,0,sizeof(x))
#define msu(x) memset(x,0x3f,sizeof(x))
#define msl(x) memset(x,0xcf,sizeof(x))
#define gc() getchar()
#define pc(x) putchar(x)
#define psb(x) push_back(x)
#define ppb() pop_back()
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
template<class A,class B> inline void ckmax(A &x,B y){x=(x>(y)?x:(y));}
template<class A,class B> inline void ckmin(A &x,B y){x=(x<(y)?x:(y));}
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
pii dt[100100];
int pos[100100],qu[100100];
vector<int> qs[100100];
lf dp[2][32][32];
lf pw2[35],pw3[35];
lf ans[100100];
lf cal(int i,int j,int dx){
    return (lf)dx/pw2[i]/pw3[j];
}
int main(){
    n=read();q=read();
    rep(i,1,n){
        int p=read(),t=read(),x=read();
        dt[i]={t,x};
        pos[i]=p;
    }
    rep(i,1,q){
        qu[i]=read();
        int ps=lower_bound(pos+1,pos+1+n,qu[i])-pos;
        if(ps==n+1)ps--;
        qs[ps].push_back(i);
    }
    pw2[0]=pw3[0]=1;
    rep(i,1,30)
        pw2[i]=pw2[i-1]*2,
        pw3[i]=pw3[i-1]*3;
    rep(j,0,30)
        rep(k,0,30)
            dp[0][j][k]=1e18;
    dp[0][0][0]=0;
    rep(i,1,n){
        if(dt[i].se==1){
            int dx=pos[i]-pos[i-1];
            rep(j,0,30)
                rep(k,0,30)
                    dp[i&1][j][k]=dp[i&1^1][j][k]+cal(j,k,dx);
        }else if(dt[i].se==2){
            rep(j,0,30)
                rep(k,0,30){
                    int dx=pos[i]-pos[i-1];
                    if(j>=1)dp[i&1][j][k]=min(dp[i&1^1][j][k]+cal(j,k,dx),dp[i&1^1][j-1][k]+dt[i].fi+cal(j-1,k,dx));
                    else dp[i&1][j][k]=dp[i&1^1][j][k]+cal(j,k,dx);
                }
        }else if(dt[i].se==3){
            rep(j,0,30)
                rep(k,0,30){
                    int dx=pos[i]-pos[i-1];
                    if(k>=1)dp[i&1][j][k]=min(dp[i&1^1][j][k]+cal(j,k,dx),dp[i&1^1][j][k-1]+dt[i].fi+cal(j,k-1,dx));
                    else dp[i&1][j][k]=dp[i&1^1][j][k]+cal(j,k,dx);
                }
        }else if(dt[i].se==4){
            rep(j,0,30)
                rep(k,0,30){
                    int dx=pos[i]-pos[i-1];
                    if(j>=2)dp[i&1][j][k]=min(dp[i&1^1][j][k]+cal(j,k,dx),dp[i&1^1][j-2][k]+dt[i].fi+cal(j-2,k,dx));
                    else dp[i&1][j][k]=dp[i&1^1][j][k]+cal(j,k,dx);
                }
        }
        for(int id:qs[i]){
            lf tmp=1e18;
            rep(j,0,30)
                rep(k,0,30)
                    ckmin(tmp,dp[i&1][j][k]+cal(j,k,qu[id]-pos[i]));
            ans[id]=tmp;
        }
    }
    rep(i,1,q)
        pf("%.8lf\n",ans[i]);
}