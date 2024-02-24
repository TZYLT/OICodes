#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 1;
bitset<maxn> num;
vector<int> prime;
inline void init(int n) {
	for (int i = 2; i <= n; ++i) {
		if (!num[i])
			prime.push_back(i);
		for (int j = 0; j < prime.size(); ++j) {
			if (i * prime[j] >= n)
				break;
			num[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
bool hw(int x){
	int t=x,ans=0;
	while(t){
		ans=ans*10+t%10;
		t/=10;
	}
	return ans==x;
}
int a=5,b=99999999;
int main() {
	//scanf("%d%d",&a,&b);
	init(b);
	for(auto u:prime)
		if(hw(u)&&u>=a)printf("%d ",u);
	return 0;
}
