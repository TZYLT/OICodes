#include<bits/stdc++.h>
using namespace std;
#define M 2020
#define p 998244353
long long a[M],s[M],dp[M][M],sm[M],n;
vector<int> bk[M],sum[M];
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	dp[0][0]=1;	
			
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++)
			sm[i]=s[i]%j;
		
        for(int i=1;i<=n;i++)
            bk[i].clear(),sum[i].clear();

        for(int i=1;i<=n;i++)
            sum[sm[i]].push_back((sum[sm[i]].back()+dp[i][j-1])%p),
            bk[sm[i]].push_back(i);
            
		for(int i=1;i<=n;i++)	
			dp[i][j]=(dp[i][j]+sum[sm[i]][lower_bound(bk[sm[i]].begin(),bk[sm[i]].end(),i)-bk[sm[i]].begin()])%p;
	}
			
				
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+dp[n][i])%p;
	printf("%lld\n",ans);
			
			
	//for(int i=0;i<=n;i++){
	//	for(int j=1;j<=n;j++)
	//		printf("%lld ",dp[i][j]);
	//	printf("\n");
	//}
}