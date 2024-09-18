#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
map<long long,long long> f,l,r;
void sol(long long n){
    if(f.count(n))return;
    long long lc=(n+1)>>1,rc=n-lc;
    sol(lc);sol(rc);
    f[n]=(f[lc]+f[rc]+1ll*rc%p*r[lc]%p+1ll*lc%p*l[rc]%p+1ll*rc%p*lc%p-1)%p;
    l[n]=(l[lc]+l[rc]+rc-1)%p;
    r[n]=(r[lc]+r[rc]+lc-1)%p;
}
long long t,n;
int main(){
    scanf("%lld",&t);
    f[1]=l[1]=r[1]=0;
    while(t--){
        scanf("%lld",&n);
        sol(n);
        printf("%lld\n",(f[n]+1ll*n%p*(n%p+1)/2)%p);
    }
}