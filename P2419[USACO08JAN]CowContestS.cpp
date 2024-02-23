#include<bits/stdc++.h>
using namespace std;
int d[110][110],n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x][y]=1;
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=d[i][j]||(d[i][k]&&d[k][j]);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++)
			if(d[i][j]||d[j][i]) sum++;
		if(sum==n-1)ans++;
	}
	printf("%d\n",ans);
}