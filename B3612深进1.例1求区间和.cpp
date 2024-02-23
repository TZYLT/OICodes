#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100];
long long b[100100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		b[i]=a[i]+b[i-1];
	scanf("%d",&m);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%ld\n",b[r]-b[l-1]);
	}
}
