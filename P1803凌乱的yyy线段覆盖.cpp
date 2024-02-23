#include<bits/stdc++.h>
using namespace std;
pair<int,int> x[2000000];
int main() {
	int n,sum=1,mi;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&x[i].second,&x[i].first);
	sort(x+1,x+n+1);
	mi=x[1].first;
	int j=1;
	while(j<=n) {
		j++;
		if(x[j].second>=mi) {
			sum++;
			mi=x[j].first;
		}
	}
	printf("%d\n",sum);
	return 0;
}
