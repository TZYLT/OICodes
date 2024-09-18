#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100],sorted[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(sorted,0,sizeof(sorted));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sorted[i]=a[i];
		sort(sorted+1,sorted+1+n);
		int num=unique(sorted+1,sorted+1+n)-sorted-1;
		for(int i=1;i<=n;i++)
			printf("%d ",lower_bound(sorted+1,sorted+1+num,a[i])-sorted);
		printf("\n");
	}
}
