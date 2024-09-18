#include<bits/stdc++.h>
using namespace std;
#define M 2000
int n,m,t,k;
int c[2020][2020],w[2020][2020],s[2020][2020];
int main(){
	freopen("P2822_2.in","r",stdin);
	freopen("P2822_2.ans","w",stdout);
	scanf("%d%d",&t,&k);
	for(int i=1;i<=M;i++)
		for(int j=1;j<=M;j++)
			c[i][j]=0;
	c[1][1]=1;for(int i=0;i<=2000;i++) c[i][0]=1;
	for(int i=2;i<=M;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;	
	for(int i=1;i<=M;i++)
		for(int j=1;j<=i;j++)
			w[i][j]=(c[i][j]==0);
	
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+w[i][j];
		s[i][i+1]=s[i][i];
	}
	while(t--){
		scanf("%d%d",&n,&m);
		if(m>n) m=n;
		printf("%d\n",s[n][m]);
	}
	
	
	
}
