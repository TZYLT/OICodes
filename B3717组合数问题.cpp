#include<bits/stdc++.h>
using namespace std;
int inv[5002050];
const int p=998244353;
int t,N,n,m,a,b;
int ans;
int sum[5000500],mus[5000500];
void write(long long x) {
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main() {
	inv[1]=1;
	scanf("%d%d",&t,&N);
	N+=100;
	for(int i=2;i<=N;++i)
		inv[i]=(long long)(p-p/i)*inv[p%i]%p;
	mus[0]=sum[0]=mus[1]=sum[1]=1;
	for(int i=2;i<=N;++i)
		sum[i]=(long long)sum[i-1]*i%p
		,mus[i]=(long long)mus[i-1]*inv[i]%p;
	while(t--){
		scanf("%d%d",&n,&m);
		//printf("%lld\n",(long long)((long long)sum[n]*mus[m]%p)*mus[n-m]%p);
		ans^=(long long)((long long)sum[n]*mus[m]%p)*mus[n-m]%p;
	}
	printf("%d\n",ans);
}
