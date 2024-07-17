#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long pr[105]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127};
struct dt{
    long long v,p,m,l;
    friend bool operator<(dt x,dt y){return x.v<y.v;}
};
priority_queue<dt> q;
int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=31;i++){
		long long t=pr[i];
		for(long long j=1;t<=n;j++,t*=pr[i])
			q.push((dt){t,pr[i],j,i-1});
	}
	while(k--){
		dt x=q.top();q.pop();
		if(!k){
			printf("%lld\n",x.v);
			return 0;
		}
		if(x.m>1)
			for(int i=1;i<=x.l;i++)
				q.push((dt){x.v/x.p*pr[i],x.p,x.m-1,i});	
	}
	
}
