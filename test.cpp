#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int main(){
    double st=clock();long long ans=1;
    for(long long i=1;i<=3e8;i++)ans=ans*i%mod;
    printf("%lld\n%.2lfms",ans,clock()-st);
}