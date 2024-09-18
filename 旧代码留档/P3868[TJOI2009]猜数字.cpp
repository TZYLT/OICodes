#include<bits/stdc++.h>
#define ll long long
const int NR=11;
using namespace std;
ll mod(ll a,ll b) {
	return (a%b+b)%b;
}
ll mul(ll a,ll b,ll m) {
	ll res=0,base=a;
	while(b) {
		if(b&1)
			res=(res+base)%m;
		base=2*base%m;
		b>>=1;
	}
	return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if(!b) {
		x=1,y=0;
		return 1;
	}
	ll X,Y;
	exgcd(b,a%b,X,Y);
	x=Y,y=X-(a/b)*Y;
	return x;
}
ll n,M=1,x,y,ans,a[NR],b[NR];
int main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld",a+i);
	for(int i=1; i<=n; ++i)
		scanf("%lld",b+i),M*=b[i],a[i]=mod(a[i],b[i]);//先模一遍对答案不会有影响
	for(int i=1; i<=n; ++i)
		ans=mod((ans+mul(mul(a[i],(M/b[i]),M),mod(exgcd(M/b[i],b[i],x,y),M),M)),M);//求答案
	printf("%lld\n",ans);
	return 0;
}
