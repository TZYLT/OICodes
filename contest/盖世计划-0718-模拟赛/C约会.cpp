#include<bits/stdc++.h>
using namespace std;
long long maxv=1000000000;
long long minv=-1000000000;
struct dot{
	long long x,y;
};
long long dis(dot x,dot y){
	return abs(x.x-y.x)+abs(x.y-y.y);
}
dot a[2020];
int n,k;
long long check(dot x){
	long long d[2020];
	for(int i=1;i<=n;i++)
		d[i]=dis(x,a[i]);
	sort(d+1,d+1+n);
	long long ans=0;
	for(int i=1;i<=k;i++)
		ans+=d[i];
	return ans;
}

long long searchY(long long x,long long l,long long r){
	if(l==r)return check((dot){x,l});
	if(l+1==r)return min(check((dot){x,l}),check((dot){x,r}));
	if(l+2==r)return min(check((dot){x,l}),searchY(x,l+1,r));
	long long midl=l+(r-l)/3,midr=r-(r-l)/3;
	long long ansl=check((dot){x,midl}),ansr=check((dot){x,midr});
	//printf("%.1lf:[%.1lf,%.1lf]:%lld,%lld\n",x,l,r,ansl,ansr);
    if(ansl>ansr)return searchY(x,midl,r);
	else if(ansl<ansr)return searchY(x,l,midr);
	else if(ansl==ansr)return searchY(x,midl,midr);
}
long long searchX(long long l,long long r){
	
	if(l==r)return searchY(l,minv,maxv);
	if(l+1==r)return min(searchY(l,minv,maxv),searchY(r,minv,maxv));
	if(l+2==r)return min(searchY(l,minv,maxv),searchX(l+1,r));
	long long midl=l+(r-l)/3,midr=r-(r-l)/3;
	long long ansl=searchY(midl,minv,maxv),ansr=searchY(midr,minv,maxv);
	//printf("X:[%.1lf,%.1lf]:%lld,%lld\n",l,r,ansl,ansr);
    if(ansl>ansr)return searchX(midl,r);
	else if(ansl<ansr)return searchX(l,midr);
	else if(ansl==ansr)return searchX(midl,midr);
}
int main(){
    freopen("dating.in","r",stdin);
    freopen("dating.out","w",stdout);
    srand(time(0));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
    long long ans=searchX(minv,maxv);
			
	// for(int i=minv;i<=maxv;i+=20000){
	// 	if(i%5000000==0)cerr<<i<<' '<<searchY(i,minv,maxv)<<endl;
	// }
		
	printf("%lld\n",ans);
}
