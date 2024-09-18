#include<bits/stdc++.h>
using namespace std;
int t;
long long n,k,a[200005],p;
bool flag;
int main(){
	cin>>t;
	while(t--) {
		scanf("%lld%lld",&n,&k);
		for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		flag=0,p=1,a[n+1]=1000000000000000;
		for(int i=1; i<=n; i++) {
			while(a[p]<a[i]+k)++p;
			if(a[p]==a[i]+k) {
				flag=1;
				break;
			}
		}
		printf("%s\n",(flag?"YES":"NO"));
	}
	return 0;
}
