#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
int main(){
    long long ans=0;
    for(int i=1;i<=1e9;i++){
        ans=(ans+((i&1)?1:-1)*(2ll*i*i%p*i%p+i)%p)%p;
        if(i%10000000==0)printf("%lld,",(ans+p)%p);
    }
}