#include<bits/stdc++.h>
using namespace std;
int ans,a[150][150],n;
int main(){
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i-1][j];
		}
	}
	for(i=1;i<=n;++i){
		for(k=1;k<=i;++k){
			int f[150]={0},dp[150]={0};
			for(j=1;j<=n;++j){
				f[j]=a[i][j]-a[i-k][j];
				dp[j]=max(dp[j-1]+f[j],f[j]);
				ans=max(ans,dp[j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
