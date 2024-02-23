#include<bits/stdc++.h>
using namespace std;
int n,w,a[1005],f[1005][10005];
const int mod=1e9+7;
int main() {
	cin >> n >> w ;
	for(int i=1; i<=n; i++) cin >> a[i] ;
	f[0][0]=1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=w; j++) {
			f[i][j]=f[i-1][j];
			if(j>=a[i]) 
				f[i][j]=(f[i][j]+f[i][j-a[i]])%mod;
		}
	}
	cout << f[n][w] ;
	return 0;
}
