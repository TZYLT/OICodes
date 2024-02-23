#include<bits/stdc++.h>
using namespace std;
int main() {
	int c,y;
	long long n,ans=0;
	int k,lastweek;
	scanf("%lld %d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&c,&y);
		if(i==1) lastweek=c;
		else lastweek=min(lastweek+k,c);
		ans+=lastweek*y;
	}
	printf("%lld\n",ans);
	return 0;
}
