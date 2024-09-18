#include<bits/stdc++.h>
using namespace std;
int f[310][310],ff[310][310];
int a[310],s[310],n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i+n]=a[i];
	for(int i=1;i<=2*n;i++)	
		s[i]=s[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	for(int l=1;l<=n;l++)
		for(int i=1;i<=2*n-l+1;i++){
			int j=i+l-1;
			if(i==j)f[i][j]=0;
			for(int k=i;k<j;k++){
				f[i][j]=min(f[i][k]+f[k+1][j]+s[j]-s[i-1],f[i][j]);
				ff[i][j]=max(ff[i][k]+ff[k+1][j]+s[j]-s[i-1],ff[i][j]);
			}
		}
	int ans=(1<<30),ansn=-(1<<30);
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i][i+n-1]),ansn=max(ansn,ff[i][i+n-1]);
	printf("%d\n%d\n",ans,ansn);
}
