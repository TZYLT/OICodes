#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,ans1,ans2,ans3;
const ll p=100003;
ll power(ll a,ll b,ll p) {
	ll ans=1%p;
	for(; b; b>>=1) {
		if(b&1) ans=(ll)ans*a%p;
		a=(ll)a*a%p;
	}
	return ans;
}
int main() {
	cin>>m>>n;
	ans1=power(m,n,p);
	ans2=m*power(m-1,n-1,p);
	ans2%=p;
	ans3=ans1-ans2;
	if(ans3<0) ans3+=p;
	cout<<ans3<<endl;
	return 0;
}
