#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for(int x=(l);x<=(r);x++)
#define per(x,l,r) for(int x=(r);x>=(l);x--)
#define ckmax(x,y) x=(x>(y)?x:(y))
#define ckmin(x,y) x=(x<(y)?x:(y))
#define frein(x) freopen(x,"r",stdin)
#define freout(x) freopen(x,"w",stdout)
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define ull unsigned long long
#define ld double
#define Ld long double
#define pii pair<int,int>
#define fi first
#define se second
constexpr int inf=0x3f3f3f3f;
constexpr ll infll=0x3f3f3f3f3f3f3f3f;

ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }while(isdigit(c)){
        x=x*10+(c^48);
        c=getchar();
    }return x*f;
}
void print(ll x){
    if(x<0){
        putchar('-');
        return print(-x);
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
/*------------------------*/
int n,k;
int a[11110];
int dp[605][6050];
void add(int a,int b,int d){
    for(int i=a;i<=600;i+=(i&(-i)))
        for(int j=b;j<=6000;j+=(j&(-j)))
            ckmax(dp[i][j],d);
}
int ask(int a,int b){
    int ans=0;
    for(int i=a;i;i-=(i&(-i)))
        for(int j=b;j;j-=(j&(-j)))
            ckmax(ans,dp[i][j]);
    return ans;
}
int ans=0;
int main(){
    n=read();k=read();
    rep(i,1,n)
        a[i]=read();
    rep(i,1,n)
        per(j,0,k){
            int x=ask(j+1,a[i]+j)+1;
            ckmax(ans,x);
            add(j+1,a[i]+j,x);
        }
    print(ans);
}