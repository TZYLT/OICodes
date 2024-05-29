#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define sq 59713600

long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
string s;
int po;
int main(){
    cin>>s;
    for(int i=s.size()-1,j=1;i>=0;i--){
        po=((long long)po+(long long)j*(s[i]-'0'))%(p-1);
        j=((long long)j*10ll)%(p-1);
    }
    printf("%lld",(qpow(sq+1,po)-qpow(p+1-sq,po)+p)%p*qpow(2ll*sq%p,p-2)%p);
}