#include<bits/stdc++.h>
using namespace std;
int a[5];
int p[5]={999911658,2,3,4679,35617},k;
int m[5];
int n,g,inv[1000010],sum[1000010],suminv[1000010];
int Combination(int n,int m,int p){
	if(m>n)return 0;
    return (long long)sum[n]*suminv[n-m]%p*suminv[m]%p;
}
int lucas(int n,int m,int mod){
	if(m==0)return 1;
    return (long long)Combination(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
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
void init(int p,int n){
    sum[0]=suminv[0]=sum[1]=suminv[1]=inv[1]=1;
    for(int i=2;i<=n;++i)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;++i)
        sum[i]=(long long)sum[i-1]*i%p,
        suminv[i]=(long long)suminv[i-1]*inv[i]%p;
}
int crt(){
	int ans=0;
	for(int i=1;i<=4;i++){
		ans=(ans+a[i]*(p[0]/p[i])%p[0]*qpow(p[0]/p[i],p[i]-2,p[i])%p[0])%p[0];
	}
	
	return ans;
}
int main(){
    scanf("%d%d",&n,&g);
	if(g%(p[0]+1)==0){
		printf("0\n");
		return 0;
	}
    for(int i=1;i<=4;i++){
    	init(p[i],50000);
    	for(int j=1;j*j<=n;j++){		
    		if(n%j==0){
    			a[i]=(a[i]+lucas(n,j,p[i]))%p[i]; 
    			if(j*j!=n)
    				a[i]=(a[i]+lucas(n,n/j,p[i]))%p[i]; 
			}		
		}	
	}
	int ans=0;
	
	ans=(long long)(ans+crt())%p[0];
	printf("%lld\n",qpow(g,ans,p[0]+1));
	
}