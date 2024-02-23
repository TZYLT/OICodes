#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,s,e;
long long a[10010000],t[10001000];
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d%d",&l,&r,&s,&e);
		int d=(e-s)/(r-l);
		a[l]+=s;
		a[l+1]+=d;a[l+1]-=s;
		a[r+1]-=(long long)(r-l+1)*d;a[r+1]-=s;
		a[r+2]+=(long long)(r-l)*d;a[r+2]+=s;
	}
	for(int i=1;i<=n;i++)
		t[i]=a[i]+t[i-1];
	long long temp=0,ans=0,maxx=-1;
	for(int i=1;i<=n;i++){
		temp+=t[i];
		ans^=temp;maxx=max(maxx,temp);
	}
	printf("%ld %ld",ans,maxx);
	
}
