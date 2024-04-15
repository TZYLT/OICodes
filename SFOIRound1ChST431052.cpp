#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int T;

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
    cin>>T;
    while(T--){
        cin>>n;
        if(n<=1)
            printf("0\n");
        else {
            long long ans=qpow(25,n-2,998244353)*(qpow(2,n,998244353)-n-1)
        }printf("%lld\n",(2ll*)%998244353);
    }
}