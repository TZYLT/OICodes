#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
    scanf("%lld%lld",&n,&k);
    for(long long l=1,r;l<=n;l=r+1){
        if(k/l==0)break;
        r=k/(k/l);
        if(r<=n)ans+=(k/l)*(l+r)*(r-l+1)/2;
        else r=n,ans+=(k/l)*(l+r)*(r-l+1)/2;
        //printf("[%lld]:ANS:%lld\n",k/l,ans);
    }
    printf("%lld\n",n*k-ans);
}
