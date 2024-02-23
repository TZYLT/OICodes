#include<bits/stdc++.h>
using namespace std;
long long n,m,c,a[1010][1010],s[1010][1010];
int main(){
	scanf("%ld%ld%ld",&n,&m,&c);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%ld",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	long long M=-100000000000;
	int x=-1,y=-1;
	for(int i=1;i<=n-c+1;i++){
		for(int j=1;j<=m-c+1;j++){
			long long t=s[i+c-1][j+c-1]-s[i-1][j+c-1]-s[i+c-1][j-1]+s[i-1][j-1];
			if(t>M){
				M=max(t,M);
				x=i;
				y=j;
			}
		}
	}
	printf("%d %d\n",x,y);
}
