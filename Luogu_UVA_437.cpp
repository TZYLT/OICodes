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
int n,m,d[95];
struct Cube{
	int x,y,z;
	bool operator > (const Cube& T){
		return ((x>T.x && y>T.y) || (x>T.y && y>T.x));
	}
}c[95];

int dp(int id){
	if(d[id]>0) return d[id];
	d[id]=c[id].z;
	for(int i=1;i<=m;i++) 
        if(c[id]>c[i]) 
            d[id]=max(d[id],dp(i)+c[id].z);
	return d[id];
}
int sol(void){
	int Ans=0;
	msz(d);
	for(int i=1;i<=m;i++) Ans=max(dp(i),Ans);
    return Ans;
}
bool inp(void){
	n=read();m=3*n;
	if(n==0) return 0;
	for(int i=1;i<=m;i+=3){
		int p=read(),q=read(),r=read();
		c[i]={p,q,r};
        c[i+1]={p,r,q};
        c[i+2]={q,r,p};
	}
	return 1;
}
int main(void){
	int cnt=0;
	while(inp())
        printf("Case %d: maximum height = %d\n",++cnt,sol());
	return 0;
}