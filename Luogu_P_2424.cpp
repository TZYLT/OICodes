#include<bits/stdc++.h>
using namespace std;
long long sol(int n){
    long long ans=0;
    for(long long l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans+=1ll*(l+r)*(r-l+1)*(n/l)/2;
    }
    return ans;
}
int l,r;
int main(){
    scanf("%d%d",&l,&r);
    printf("%lld\n",sol(r)-sol(l-1));
}