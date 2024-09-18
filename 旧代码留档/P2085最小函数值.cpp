#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010],b[10010],c[10010];
priority_queue<long long> q;
long long f(long long x,int i){
	return x*x*a[i]+x*b[i]+c[i];
}

void add(int u,int k){
	for(long long i=1;i<=k;i++)	
		q.push(-f(i,u));
}

int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++)
		add(i,1000);
	while(m--) printf("%lld ",-q.top()),q.pop();
}
