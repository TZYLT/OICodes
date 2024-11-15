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
#define p 1000000007
int T,dp[2][20][20][20][20][20][20];
inline bool ck(int a,int b,int c,int d,int e,int f,int lim){
    return (a+b+c+2*d+2*e+2*f)<=lim;
}
inline bool ckk(int a,int b,int c,int d,int e,int f,int lim){
    return (a+b+c+d+e+f)<=lim;
}
int main(){
    T=read();
    while(T--){
        int n=read();
        n*=3;
        string s;
        cin>>s;
        s=" "+s;
        dp[0][0][0][0][0][0][0]=1;
        rep(i,1,n){
            for(int a=0;ck(a,0,0,0,0,0,i)&&ck(0,0,0,a,0,0,n-i+1)&&ckk(a,0,0,0,0,0,n/3);a++)
                for(int b=0;ck(a,b,0,0,0,0,i)&&ck(0,0,0,a,b,0,n-i+1)&&ckk(a,b,0,0,0,0,n/3);b++)
                    for(int c=0;ck(a,b,c,0,0,0,i)&&ck(0,0,0,a,b,c,n-i+1)&&ckk(a,b,c,0,0,0,n/3);c++)
                        for(int d=0;ck(a,b,c,d,0,0,i)&&ck(d,0,0,a,b,c,n-i+1)&&ckk(a,b,c,d,0,0,n/3);d++)
                            for(int e=0;ck(a,b,c,d,e,0,i)&&ck(d,e,0,a,b,c,n-i+1)&&ckk(a,b,c,d,e,0,n/3);e++)
                                for(int f=0;ck(a,b,c,d,e,f,i)&&ck(d,e,f,a,b,c,n-i+1)&&ckk(a,b,c,d,e,f,n/3);f++)
                                    dp[i&1][a][b][c][d][e][f]=0;
            for(int a=0;ck(a,0,0,0,0,0,i)&&ck(0,0,0,a,0,0,n-i+1)&&ckk(a,0,0,0,0,0,n/3);a++)
                for(int b=0;ck(a,b,0,0,0,0,i)&&ck(0,0,0,a,b,0,n-i+1)&&ckk(a,b,0,0,0,0,n/3);b++)
                    for(int c=0;ck(a,b,c,0,0,0,i)&&ck(0,0,0,a,b,c,n-i+1)&&ckk(a,b,c,0,0,0,n/3);c++)
                        for(int d=0;ck(a,b,c,d,0,0,i)&&ck(d,0,0,a,b,c,n-i+1)&&ckk(a,b,c,d,0,0,n/3);d++)
                            for(int e=0;ck(a,b,c,d,e,0,i)&&ck(d,e,0,a,b,c,n-i+1)&&ckk(a,b,c,d,e,0,n/3);e++)
                                for(int f=0;ck(a,b,c,d,e,f,i)&&ck(d,e,f,a,b,c,n-i+1)&&ckk(a,b,c,d,e,f,n/3);f++)
                                    if(dp[i&1^1][a][b][c][d][e][f]){
                                        if(s[i]=='1'||s[i]=='0'){
                                            if(a<n){
                                                dp[i&1][a+1][b][c][d][e][f]+=dp[i&1^1][a][b][c][d][e][f];
                                                ckmod(dp[i&1][a+1][b][c][d][e][f],p);
                                            }
                                            if(b&&d<n){
                                                dp[i&1][a][b-1][c][d+1][e][f]+=1ll*dp[i&1^1][a][b][c][d][e][f]*b%p;
                                                ckmod(dp[i&1][a][b-1][c][d+1][e][f],p);
                                            }
                                            if(f){
                                                dp[i&1][a][b][c][d][e][f-1]+=1ll*dp[i&1^1][a][b][c][d][e][f]*f%p;
                                                ckmod(dp[i&1][a][b][c][d][e][f-1],p);
                                            }
                                        }
                                        if(s[i]=='2'||s[i]=='0'){
                                            if(b<n){
                                                dp[i&1][a][b+1][c][d][e][f]+=dp[i&1^1][a][b][c][d][e][f];
                                                ckmod(dp[i&1][a][b+1][c][d][e][f],p);
                                            }
                                            if(c&&f<n){
                                                dp[i&1][a][b][c-1][d][e][f+1]+=1ll*dp[i&1^1][a][b][c][d][e][f]*c%p;
                                                ckmod(dp[i&1][a][b][c-1][d][e][f+1],p);
                                            }
                                            if(e){
                                                dp[i&1][a][b][c][d][e-1][f]+=1ll*dp[i&1^1][a][b][c][d][e][f]*e%p;
                                                ckmod(dp[i&1][a][b][c][d][e-1][f],p);
                                            }
                                        }
                                        if(s[i]=='3'||s[i]=='0'){
                                            if(c<n){
                                                dp[i&1][a][b][c+1][d][e][f]+=dp[i&1^1][a][b][c][d][e][f];
                                                ckmod(dp[i&1][a][b][c+1][d][e][f],p);
                                            }
                                            if(a&&e<n){
                                                dp[i&1][a-1][b][c][d][e+1][f]+=1ll*dp[i&1^1][a][b][c][d][e][f]*a%p;
                                                ckmod(dp[i&1][a-1][b][c][d][e+1][f],p);
                                            }
                                            if(d){
                                                dp[i&1][a][b][c][d-1][e][f]+=1ll*dp[i&1^1][a][b][c][d][e][f]*d%p;
                                                ckmod(dp[i&1][a][b][c][d-1][e][f],p);
                                            }
                                        }
                                    }

        }
        int ans=1;
        rep(i,1,n/3)
            ans=1ll*ans*i%p;
        prtl(1ll*dp[n&1][0][0][0][0][0][0]*ans%p);
        msz(dp);
    }
}