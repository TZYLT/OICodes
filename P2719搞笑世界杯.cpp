#include<bits/stdc++.h>
using namespace std;
#define M 1000
double f[M][M];
int n;
int main(){
	scanf("%d",&n);
	n/=2;
	for(int i=2;i<=n;i++)
		f[i][0]=f[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i][j-1]+f[i-1][j])*0.5;
	printf("%.4lf\n",f[n][n]);
}