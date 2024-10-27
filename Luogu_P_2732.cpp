#include<bits/stdc++.h>
using namespace std;
long long dp[6][6][6][6][6];
long long s[105][6],ns[6],pr_s[105],pr[6],val[105];
long long S,b,n,c,k,p,cnt,sum;
long long to[10005];
int main(){
	scanf("%lld",&S);
	for(int i=1;i<=S;i++){
		scanf("%lld",&n);
		for(int j=1;j<=n;j++){
			scanf("%lld%lld",&c,&k);
			if(!to[c]) to[c]=++cnt;
			s[i][to[c]]=k;
		}
		scanf("%lld",pr_s+i);
	}
	scanf("%lld",&b);
	for(int i=1;i<=b;i++){
		scanf("%lld%lld%lld",&c,&k,&p);
		ns[to[c]]=k;
		pr[to[c]]=p;
		sum+=k*p;
	}
	for(int i=1;i<=S;i++){
		for(int j=1;j<=cnt;j++)
			val[i]=val[i]+s[i][j]*pr[j];
		val[i]-=pr_s[i];
	}
	for(int i=1;i<=S;i++)
		for(int i1=s[i][1];i1<=ns[1];i1++)
			for(int i2=s[i][2];i2<=ns[2];i2++)
				for(int i3=s[i][3];i3<=ns[3];i3++)
					for(int i4=s[i][4];i4<=ns[4];i4++)
						for(int i5=s[i][5];i5<=ns[5];i5++)
							dp[i1][i2][i3][i4][i5]=max(dp[i1][i2][i3][i4][i5],dp[i1-s[i][1]][i2-s[i][2]][i3-s[i][3]][i4-s[i][4]][i5-s[i][5]]+val[i]);
	printf("%lld\n",sum-dp[ns[1]][ns[2]][ns[3]][ns[4]][ns[5]]);
	return 0;
}