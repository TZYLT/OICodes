#include<bits/stdc++.h>
using namespace std;
int v[30010],p[30010],k=0;
void linearSieve(int n){
    v[1]=1;
    for(int i=2;i<=n;i++){
        if(!v[i])p[++k]=i;
        for(int j=1;j<=k&&i*p[j]<=n;j++){
            v[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
long long mul(long long a,long long b,long long mod){
	long long ans=0;
	while(b){
		if(b&1)ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans;
}
long long qpow(long long a,long long k,long long p){
    long long res=1;
    while(k){
        if(k&1) res=mul(res,a,p)%p;
        a=mul(a,a,p)%p;
        k>>=1;
    }
    return res%p;
}
#define inf 1000000000000000000
long long phii(long long n){
    if(n==1)return 1;
    long long cnt=0,sum=1;
    for(int i=1;i<=k;i++){
        cnt=0;
        while(!(n%p[i]))n/=p[i],cnt++;
        if(cnt==0)continue;
        sum*=(qpow(p[i],cnt,inf)-qpow(p[i],cnt-1,inf));
    }
    sum*=(n==1?1:n-1);
    return sum;
}
long long q,a,m;
long long sol(long long m){
    if(!a)return m;
    if(a==1)return 1;
    if(m==1)return 100;
    long long t=phii(m),g=__gcd(m,t);
    long long l=m*t/g;
    long long ans=qpow(a,sol(t),l);
    while(ans<100)ans+=l;
    return ans;
}

int main(){
    linearSieve(30000);
    
    scanf("%lld",&q);
    while(q--){
        scanf("%lld%lld",&a,&m);
        printf("%lld\n",sol(m));
    }
}