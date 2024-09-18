#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long qpow(long long a,long long k,long long p){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int sol(long long n){
    int ans=(4ll*qpow(2,n,mod)%mod-3ll*n%mod-5)%mod;
    int rem=(4ll*qpow(2,n,6)%6-3ll*n%6-5)%6;
    ans=(ans+mod)%mod;
    rem=(rem+6)%6;
    ans-=rem;
    ans=1ll*ans*qpow(6,mod-2,mod)%mod;
    ans+=(n&1)?0:1;
    return ans=(ans+mod)%mod;
}
long long l,r;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>l>>r;
    cout<<(sol(r)-sol(l-1)+mod)%mod<<endl;
}