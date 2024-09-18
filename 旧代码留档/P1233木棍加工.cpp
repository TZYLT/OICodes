#include<bits/stdc++.h>
using namespace std;
struct stick {
	int l,r;
} a[11000];
int n;
int dp[11000],ans;
bool cmp(stick x,stick y) {
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+1+n,cmp);
	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(a[j].r>a[i].r) {
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		ans=max(dp[i],ans);
	}
	cout<<ans+1;
	return 0;
}
