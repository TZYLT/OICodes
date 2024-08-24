#include<bits/stdc++.h>
using namespace std;
long long t,c;
long long sum[2002000],tot;
void init(){
    long long len=1<<(__lg(c)+1);
    sum[0]=(c==1);
    for(long long i=1;i<len;i++)
        sum[i]=sum[i-1]+(__gcd(i*c^c,c)==1);
    tot=sum[len-1];
}
long long cal(long long n){
    long long len=1<<(__lg(c)+1);
    return 1ll*tot*(n/len)+sum[n%len];
}
int main(){
    scanf("%lld%lld",&t,&c);
    init();
    while(t--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",cal(r)-cal(l-1));
    }
}