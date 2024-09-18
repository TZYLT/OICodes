#include<bits/stdc++.h>
using namespace std;
long long t,l,r;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        if(r>l*3+100){
            printf("%lld\n",r/2);
            continue;
        }
        long long ans=0;
        l--;
        for(long long i=1,j;i<=l;i=j+1){
            j=min(l/(l/i),r/(r/i));
            ans+=((r/i)-(l/i)>=2)*(j-i+1);
        }
        printf("%lld\n",max(0ll,r/2-l)+ans);
    }
}