#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500];
#define C 500500
int l[4*C+1],r[4*C+1];
long long sum[4*C+1];
void build(int p,int li,int ri){
	l[p]=li;r[p]=ri;
	if(li==ri){
		sum[p]=a[li];
		return;
	}
	int mid=(li+ri)/2;
	build(p*2,li,mid);
	build(p*2+1,mid+1,ri);
	sum[p]=min(sum[p*2],sum[p*2+1]);
}
int ask(int p,int li,int ri){
	if(li<=l[p]&&ri>=r[p]) return sum[p];
	int mid=(l[p]+r[p])/2;
	int v=0x3f3f3f3f;
	if(li<=mid)v=min(v,ask(p*2,li,ri));
	if(ri>mid)v=min(v,ask(p*2+1,li,ri));
	return v;
} 
int ans=0xcfcfcfcf;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),a[i]+=a[i-1];
	build(1,0,n);
	for(int i=1;i<=n;i++)
		ans=max(ans,a[i]-ask(1,max(0,i-m),max(i-1,0)));
	printf("%d\n",ans);
}