#include<bits/stdc++.h>
using namespace std;
int a[1001000],h,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&h);
	for(int i=h;i;i=a[i])
		printf("%d ",i);
}
