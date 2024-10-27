#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll qpow(ll a,ll b,ll p){
    ll res=1;
    while(b){
        if(b&1)(res*=a)%=p;
        (a*=a)%=p;b>>=1;
    }
    return res;
}
int a,b,p;
int main(){
    scanf("%d%d%d",&a,&b,&p);
    printf("%d^%d mod %d=%lld\n",a,b,p,qpow(a,b,p));
}