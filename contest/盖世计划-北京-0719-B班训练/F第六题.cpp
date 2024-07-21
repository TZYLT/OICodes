#include<bits/stdc++.h>
using namespace std;
int n,a[(1<<19)];
priority_queue<int> q;
long long ans;
int popcount(int x){
	int ans=0;
	while(x){
		if(x&1)ans++;
		x>>=1;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=n;i>=1;i--){
		q.push(-a[i]);
		if(a[i]==-1)break;
		if(popcount(i)==1)ans-=q.top(),q.pop();
	}
	printf("%lld\n",ans);
}
