#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[100100],b[100100],sa,sb,sab;
int n,k;
long long qpow(long long a,long long k,long long p){
	long long res=1;
	while(k){
		if(k&1) res=(res*a)%p;
		a=(a*a)%p;
		k>>=1;
	}
	return res%p;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sa=(a[i]+sa)%mod;
    }
		
	for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        sb=(b[i]+sb)%mod;	
    }
		
    if(k==0){
        printf("%d\n",n);
        return 0;
    }
	for(int i=1;i<=n;i++)
		sab=((long long)a[i]*b[i]+sab)%mod;
    int ans=((long long)sa*sb%mod)*qpow(sab,k-1,mod)%mod;
	printf("%lld\n",(ans+mod)%mod);
}