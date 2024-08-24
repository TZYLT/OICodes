#include<bits/stdc++.h>
using namespace std;
#define M 5050
int n,m,s[M][M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		s[x+1][y+1]+=v;
	}
	for(int i=1;i<=5001;i++)
		for(int j=1;j<=5001;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
	int ans=0;
	for(int i=m;i<=5001;i++)
		for(int j=m;j<=5001;j++)
			ans=max(ans,s[i][j]-s[i-m][j]-s[i][j-m]+s[i-m][j-m]);
	printf("%d\n",ans);
	return 0;
}