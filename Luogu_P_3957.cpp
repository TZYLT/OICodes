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
#define ull unsigned ll
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
#define maxn 500000 
ll sum=0;
struct node{
	int p,w;
}a[maxn+1];
int L,R; 
ll dp[maxn+1],q[maxn+1];
int n,d,k; 
int ans=-inf;
ll ck(int l,int r) {
	ms(dp,0xcf);dp[0]=0;
	ms(q,0);
	
	int h=1,t=0,j=0;
	rep(i,1,n){
        while(a[i].p-a[j].p>=l&&j<i){
            if(dp[j]!=0xcfcfcfcfcfcfcfcf){
                while(h<=t&&dp[q[t]]<=dp[j])t--;
                q[++t]=j;
            }
            j++;
        }
        while (h<=t&&a[i].p-a[q[h]].p>r)h++;
        if(h<=t)dp[i]=dp[q[h]]+a[i].w;
    }
    ll ans=0xcfcfcfcfcfcfcfcf;
    rep(i,1,n)
        ckmax(ans,dp[i]);
    return ans;
}

int main(){
	n=read();d=read();k=read();
	rep(i,1,n){
		a[i].p=read();
        a[i].w=read();
		if(a[i].w>0){
			sum+=a[i].w;   
			ckmax(R,a[i].p);  
		}  
	}
	if(sum<k){
		prtl(-1);
		return 0;
	}
	while (L<=R){
		int mid=((L+R)/2);
		int l=max(1,d-mid),r=d+mid;
		if(ck(l,r)<k) L=mid+1;
		else ans=mid,R=mid-1;
	}
	prtl(ans);
	return 0;
}