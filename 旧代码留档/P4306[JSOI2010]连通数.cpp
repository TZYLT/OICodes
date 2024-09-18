#include<bits/stdc++.h>
using namespace std;
int n,ans;
bitset<2010> d[2010];
int main(){
	scanf("%d",&n);
	char c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			do{
				c=getchar();
			}while(c!='0'&&c!='1');
			d[i][j]=c-'0';	
	}
	for(int i=1;i<=n;i++)
		d[i][i]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(d[i][k])
				d[i]=d[i]|d[k];
	for(int i=1;i<=n;i++)
		ans+=d[i].count();
	printf("%d\n",ans);
}