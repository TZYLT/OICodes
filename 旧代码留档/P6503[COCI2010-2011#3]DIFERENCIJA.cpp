#include<bits/stdc++.h>
using namespace std;
#define N 300200
long long ans,mid,a[N],n,q[N],head=1;
long long sum() {
	head=1;
	long long now=0,sum=0;
	for(int i=1; i<=n; i++) {
		while(head>1&&a[q[head]]<a[i]) {
			now-=(q[head]-q[head-1])*a[q[head]];
			head--;
		}
		now+=(i-q[head])*a[i];
		sum+=now;
		q[++head]=i;
	}
	return sum;
}
int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ans+=sum();
	for(int i=1;i<=n;i++)a[i]*=(-1);
	ans+=sum();
	printf("%lld\n",ans);
	return 0;
}
