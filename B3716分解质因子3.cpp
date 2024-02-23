#include<bits/stdc++.h>
using namespace std;
int mn[100020200],p[20000010],k;
bool v[100020200];
int T,n;
void gp(void){
	v[1]=1;
	for(int i=2;i<=100000000;i++){
		if(!v[i])p[++k]=i,mn[i]=i;
		for(int j=1;j<=k&&i*p[j]<=100000000;j++){
			v[i*p[j]]=1;
			mn[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	gp();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0;
		while(n>1){
			ans^=mn[n];
			n/=mn[n];
		}
		printf("%d\n",ans);
	}
}
