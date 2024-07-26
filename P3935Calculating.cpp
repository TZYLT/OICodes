#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int cal(long long n){
    int ans=0;
    for(long long l=1,r;l<=n;l=r+1){
        r=(n/(n/l));
        ans=(ans+1ll*(r-l+1)*(n/l)%p)%p;
    }   
    return ans;
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    printf("%d\n",((cal(b)-cal(a-1))%p+p)%p);
}