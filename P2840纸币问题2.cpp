#include<bits/stdc++.h>
using namespace std;
int n,w,a[10010],f[10010];
const int m=1000000007;
int main(){
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	f[0]=1;
	for(int i=1;i<=w;i++)
		for(int j=1;j<=n;j++)
			if(a[j]<=i)f[i]=(f[i]+f[i-a[j]])%m;
	
	printf("%d\n",f[w]);
}
