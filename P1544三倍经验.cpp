#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
ll f[110][110][110];
ll a[110][110];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(k>n) k=n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++) cin>>a[i][j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			for(int p=0; p<=k; p++)
				f[i][j][p]=-inf;
	f[1][1][0]=a[1][1];
	f[1][1][1]=a[1][1]*3;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			for(int p=0; p<=k; p++) {
				f[i+1][j][p]=max(f[i+1][j][p],f[i][j][p]+a[i+1][j]);
				f[i+1][j+1][p]=max(f[i+1][j+1][p],f[i][j][p]+a[i+1][j+1]);
				f[i+1][j][p+1]=max(f[i+1][j][p+1],f[i][j][p]+a[i+1][j]*3);
				f[i+1][j+1][p+1]=max(f[i+1][j+1][p+1],f[i][j][p]+a[i+1][j+1]*3);
			}
	ll ans=-inf;
	for(int i=1; i<=n; i++) for(int p=0; p<=k; p++) ans=max(ans,f[n][i][p]);
	cout<<ans;
	return 0;
}
