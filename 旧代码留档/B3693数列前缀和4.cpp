#include<bits/stdc++.h>
using namespace std;
unsigned long long sum[2050][2050],temp,n,m,q,ans;
unsigned long long u,v,x,y;
int main()
{
	unsigned long long t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>q;
		for(unsigned long long i=1;i<=n;i++)
			for(unsigned long long j=1;j<=m;j++){
				cin>>temp;
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+temp;
			}
		for(unsigned long long i=1;i<=q;i++) {
			cin>>u>>v>>x>>y;
			ans^=sum[x][y]+sum[u-1][v-1]-sum[u-1][y]-sum[x][v-1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
