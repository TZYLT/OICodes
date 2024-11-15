#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define fi first
#define se second
#define pb push_back
#define pii pair<LL,LL>
#define mem(a,x) memset((a),(x),sizeof(a))

template<typename type>
inline void read(type &x)
{
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}

template<typename type>
inline void write(type x,bool mode=1)
{
	x<0?x=-x,putchar('-'):0;static short Stack[50],top(0);
	do Stack[++top]=x%10,x/=10; while(x);
	while(top) putchar(Stack[top--]|48);
	mode?putchar('\n'):putchar(' ');
}

LL qsm(LL a,LL b,LL mod){
	LL ans=1,sum=a;
	while(b){
		if(b&1) ans=ans*sum%mod;
		sum=sum*sum%mod;
		b>>=1;
	}
	return ans;
}
const LL N=3e2+10,M=5e4+10,mod=998244353;

LL n,k,f[2][M],g1[2][M],g2[2][M],sum[2][M][4];
LL cal(LL i,LL l,LL r,LL op){
	return (sum[i][r][op]-(l>0?sum[i][l-1][op]:0)+mod)%mod;
}
void solve(){
	read(n),read(k);
	f[0][0]=1;
	LL op=1;
	for(LL i=1;i<=n;i++,op^=1){
		sum[op^1][0][0]=f[op^1][0];
		for(LL j=1;j<=k;j++) sum[op^1][j][0]=(sum[op^1][j-1][0]+f[op^1][j])%mod;
		for(LL j=1;j<=k;j++) sum[op^1][j][1]=(sum[op^1][j-1][1]+f[op^1][j]*j%mod)%mod;
		sum[op^1][0][2]=g1[op^1][0];
		for(LL j=1;j<=k;j++) sum[op^1][j][2]=(sum[op^1][j-1][2]+g1[op^1][j])%mod;
		sum[op^1][0][3]=g2[op^1][0];
		for(LL j=1;j<=k;j++) sum[op^1][j][3]=(sum[op^1][j-1][3]+g2[op^1][j])%mod;
		for(LL j=0;j<=k;j++){
			f[op][j]=cal(op^1,max((LL)0,j-i+1),j,0);
			g1[op][j]=(cal(op^1,max((LL)0,j-i+1),j,2)+i*j%mod*cal(op^1,max((LL)0,j-i+1),j,0)%mod-i*cal(op^1,max((LL)0,j-i+1),j,1)%mod+mod)%mod;
			g2[op][j]=(cal(op^1,max((LL)0,j-i+1),j,3)+(n-i+1)*j%mod*cal(op^1,max((LL)0,j-i+1),j,0)%mod-(n-i+1)*cal(op^1,max((LL)0,j-i+1),j,1)%mod+mod)%mod;
		}
	}
	LL sum=n*(n+1)*(2*n+1)/6;
	LL ans=sum*f[n&1][k]%mod;
	ans=(ans-g1[n&1][k]+g2[n&1][k]+mod)%mod;
	write(ans);
}

int main(){
	solve();
}