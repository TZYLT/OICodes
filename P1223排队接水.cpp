#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
pair<int ,int> a[1001000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
		sum+=a[n-i+1].first*(i-1);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].second);
	printf("\n%.2lf\n",(double)sum/n);
}
