#include<bits/stdc++.h>
using namespace std;
int n,m,p[100100],a,b,c,u[100100],k[100100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<m;i++){
		u[min(p[i],p[i+1])]++;
		u[max(p[i],p[i+1])]--;
	}
	for(int i=1;i<=n;i++)
		k[i]=k[i-1]+u[i];
	long long ans=0;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		ans+=min((long long)k[i]*a,(long long)k[i]*b+c);
		//printf("[%d]:%d\n",i,min(k[i]*a,c+k[i]*b));
	}
	printf("%ld\n",ans);
}
