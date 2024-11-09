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
void prts(ll x,char c){prt(x);pc(c);}
/*------------------------*/
string s;
int n,m;
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;s=" "+s+" ";
    rep(i,1,m){
        int id;char c;
        cin>>c>>id;
        if(m==n&&i==1) s[id]='W';
        else s[id]=c;
    }
    rep(i,1,n){
        if(s[i]=='R'){
			if(s[i-1]=='B') s[i]='W';
			if(s[i-1]=='W') s[i]='B';
		}
		if(s[i]=='M'){
			if(s[i-1]=='B') s[i]='B';
			if(s[i-1]=='W') s[i]='W';
		}
    }
    reverse(s.begin(),s.end());
    rep(i,1,n){
        if(s[i]=='R'){
			if(s[i-1]=='B') s[i]='W';
			if(s[i-1]=='W') s[i]='B';
		}
		if(s[i]=='M'){
			if(s[i-1]=='B') s[i]='B';
			if(s[i-1]=='W') s[i]='W';
		}
    }
    rep(i,1,n)
        if(s[i]!=s[i-1])ans++;
    prt(ans);
}