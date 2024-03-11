#include<bits/stdc++.h>
using namespace std;
int a[5];
int p[5]={999911658,2,3,4679,35617};
int m[5];
int n,k,inv[100010],sum[100010],suminv[100010];
int Combination(int n,int m,int p){
	if(m>n)return 0;
	return (long long)sum[n]*suminv[n-m]%p*suminv[m]%p;
}
int lucas(int n,int m,int p){
	if(m==0)return 1;
	return (long long)Combination(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
void init(int p,int n){
    sum[0]=suminv[0]=sum[1]=suminv[1]=inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;++i)
        sum[i]=(long long)sum[i-1]*i%p,
        suminv[i]=(long long)suminv[i-1]*inv[i]%p;
}
long long qpow(long long a,long long k,long long p){
	long long res=1;
	while(k){
		if(k&1) res=(res*a)%p;
		a=(a*a)%p;
		k>>=1;
	}
	return res%p;
}
int crt(){
	int ans=0;
	for(int i=1;i<=4;i++)
		ans=(ans+a[i]*(p[0]/p[i])%p[0]*
			qpow(p[0]/p[i],p[i]-2,p[i])%p[0])%p[0];
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=4;i++){
		init(p[i],40000);
		a[i]=lucas(n,k,p[i]);
		a[i]=((long long)a[i]*qpow(inv[4],n,p[i]))%p[i];
	}
	
	int ans=(long long)crt()%p[0];
	
	init(p[0],40000);
	ans=((long long)ans*qpow(3,k,p[0]))%p[0];
	printf("%d\n",ans);
}