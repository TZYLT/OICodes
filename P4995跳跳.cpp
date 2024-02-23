#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a,a+n+1);
	int l=0,r=n,st=0;
	while(l!=r){
		st++;
		ans+=(a[l]-a[r])*(a[l]-a[r]);
		if(st&1)l++;
		else r--;
		//printf("[%d]",st&1?l-1:r+1);
	}
	printf("%lld\n",ans);
}
