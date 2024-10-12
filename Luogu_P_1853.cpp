#include<bits/stdc++.h>
using namespace std;
int w[100000],v[100000],dp[100000];
int s,n,d;
int main(){
	scanf("%d%d%d",&s,&n,&d);
	for(int i=1;i<=d;++i)
		scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;++i){
        memset(dp,0,sizeof dp);
		int m=s/1000;
		for(int j=1;j<=d;++j)
			for(int k=w[j]/1000;k<=m;++k)
				if(k>=w[j]/1000)
                    dp[k]=max(dp[k],dp[k-w[j]/1000]+v[j]);
		s+=dp[m];
	}
	printf("%d",s);
}