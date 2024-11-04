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

int pre[200100];
int sum[200100];
ll ans;
int n,t;
char c[200100];
int main(){
    t=read();
    while(t--){
        n=read();n--;
        rep(i,1,n){
            c[i]=gc();
            while(c[i]!='>'&&c[i]!='='&&c[i]!='<')c[i]=gc();
        }
        ans=0;
        per(i,1,n){
            if(c[i]=='>') sum[i]=0;
            else sum[i]=sum[i+1]+(c[i]=='<'||c[i]=='=');
            pre[i]=(c[i]=='=')?pre[i+1]:i;
        }
        per(i,1,n)
            ans+=sum[pre[i]];
        per(i,1,n)
            sum[i]=pre[i]=0;
        rep(i,1,n){
            if(c[i]=='<') sum[i]=0;
            else sum[i]=sum[i-1]+(c[i]=='>'||c[i]=='=');
            pre[i]=(c[i]=='=')?pre[i-1]:i;
        }
        rep(i,1,n)
            ans+=sum[pre[i]];
        rep(i,1,n)
            sum[i]=pre[i]=0;
        print(ans);pc('\n');
    }

}
