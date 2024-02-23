#include<bits/stdc++.h>
#define mod 1000000007
template <int C>
class BinaryIndexedTrees {
	public:
		int data[C+1],c[C+1];
		BinaryIndexedTrees()=default;
		void inti(void);
		int ask(int x);
		void add(int x,long long d);
};
template<int C>
int BinaryIndexedTrees<C>::ask(int x) {
	long long ans=0;
	for(; x; x-=x&-x)ans=(long long)(ans+c[x])%mod;
	return ans;
}
template<int C>
void BinaryIndexedTrees<C>::add(int x,long long d) {
	d%=mod;
	for(; x<=C; x+=x&-x) c[x]=(long long)(c[x]+d)%mod;
}
template<int C>
void BinaryIndexedTrees<C>::inti(void) {
	for(int i=1; i<=C; i++) data[i]=c[i]=0;
}
int qpow(int b, int p = mod - 2, int m = mod) {
	b %= m;
	int s = 1 % m;
	for(; p; p >>= 1, b = (long long)b * b % m)
		if(p & 1) s = (long long)s * b % m;
	return s;
}
BinaryIndexedTrees<100100> sum,sq;
int n,m,a[100100];
int c,x,y;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) {
		sum.add(i,a[i]);
		sq.add(i,(long long)a[i]*a[i]%mod);
	}
	while(m--) {
		scanf("%d%d%d",&c,&x,&y);
		if(c==1) {
			sum.add(x,(long long)y-(long long)(sum.ask(x)-sum.ask(x-1)));
			sq.add(x,(long long)y*y-(long long)(sq.ask(x)-sq.ask(x-1)));
		} else {
			int inv=qpow(y-x+1);
			int ave=(long long)inv*(sum.ask(y)-sum.ask(x-1))%mod;
			int ans=(long long)inv*(sq.ask(y)-sq.ask(x-1))%mod-(long long)ave*(ave)%mod;
			ans=((ans%mod)+mod)%mod;
			printf("%d\n",ans);
		}
	}
}
