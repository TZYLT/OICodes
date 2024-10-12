#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
void sol(){
    scanf("%lld%lld",&n,&m);
    if(n==m){
        printf("0\n");
        return;
    }
    if(m%n!=0){
        printf("-1\n");
        return;
    }
    long long ans=0;
    while(m>1){
        long long g=__gcd(m/__gcd(n,m),n);
        n*=g;ans++;
        //printf("%lld\n",n);
        if(__gcd(n,m)==m)break;
        if(ans>=60){
            printf("-1\n");
            return;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%lld",&t);
    while(t--){
        sol();
    }
}