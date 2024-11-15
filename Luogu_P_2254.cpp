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
int dp[205][205][205];
int _map[205][205];
int q[205],h,t;
int n,m,k;
int X,Y,ans=-inf;
int main(){
    n=read();m=read();X=read();Y=read();k=read();
    rep(i,1,n){
        string s;
        cin>>s;
        rep(j,0,m-1)
            _map[i][j+1]=(s[j]=='x');
    }
    msl(dp);
    dp[0][X][Y]=0;
    rep(i,1,k){
        int l=read(),r=read(),d=read();
        int len=(r-l+1);
        if(d==4){
            rep(k,1,n){
                h=0;t=1;
                rep(j,1,m){
                    if(_map[k][j]){h=0;t=1;continue;}
                    while(t<=h&&q[t]<j-len)t++;
                    while(t<=h&&dp[i-1][k][q[h]]-q[h]<=dp[i-1][k][j]-j)h--;
                    q[++h]=j;
                    dp[i][k][j]=dp[i-1][k][q[t]]+j-q[t];
                }
            }
        }else if(d==3){
            rep(k,1,n){
                h=0;t=1;
                per(j,1,m){
                    if(_map[k][j]){h=0;t=1;continue;}
                    while(t<=h&&q[t]-j>len)t++;
                    while(t<=h&&dp[i-1][k][q[h]]+q[h]<=dp[i-1][k][j]+j)h--;
                    q[++h]=j;
                    dp[i][k][j]=dp[i-1][k][q[t]]+q[t]-j;
                }
            }
        }else if(d==2){
            rep(k,1,m){
                h=0;t=1;
                rep(j,1,n){
                    if(_map[j][k]){h=0;t=1;continue;}
                    while(t<=h&&j-q[t]>len)t++;
                    while(t<=h&&dp[i-1][q[h]][k]-q[h]<=dp[i-1][j][k]-j)h--;
                    q[++h]=j;
                    dp[i][j][k]=dp[i-1][q[t]][k]+j-q[t];
                }
            }
        }else{
            rep(k,1,m){
                h=0;t=1;
                per(j,1,n){
                    if(_map[j][k]){h=0;t=1;continue;}
                    while(t<=h&&q[t]-j>len)t++;
                    while(t<=h&&dp[i-1][q[h]][k]+q[h]<=dp[i-1][j][k]+j)h--;
                    q[++h]=j;
                    dp[i][j][k]=dp[i-1][q[t]][k]+q[t]-j;
                }
            }
        }
        rep(j,1,n)
            rep(k,1,m)
                ckmax(ans,dp[i][j][k]);
    }
    prtl(ans);
}