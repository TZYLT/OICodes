#include<bits/stdc++.h>
using namespace std;
#define p 998244353
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
long long n,q,x,y;
int main(){
    scanf("%lld%lld",&n,&q);
    while(q--){
        scanf("%lld%lld",&x,&y);
        long long t=1;
        if(y>62)t=n;
        else{
            x>>=y;
            if(!x)t=n;
            else{
                int d=x&1;
                do x>>=1,++y;
                while((x&1)==d);
                t=y;
            }
        }
        printf("%lld\n",(qpow(2,t)-1+p)%p);
    }
}