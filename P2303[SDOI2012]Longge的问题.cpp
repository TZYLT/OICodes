#include<bits/stdc++.h>
using namespace std;
long long n;
long long cal(long long n){
    long long ans=n;
    for(long long i=2;i*i<=n;++i) 
        if(n%i==0){
        int b=0;
        while(n%i==0) ++b,n/=i;
        ans/=i;
        ans*=b*i-b+i;
    } 
    if(n>1){
        ans/=n;
        ans*=n+n-1; 
    }
    return ans;
}
int main(){
    scanf("%lld",&n);
    printf("%lld",cal(n));
    return 0;
}