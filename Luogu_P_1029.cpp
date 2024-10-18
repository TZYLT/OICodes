#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,ans;
signed main(){
    scanf("%lld%lld",&x,&y);
    int t=x*y;
    for(int i=1;i*i<=t;i++)
        if(t%i==0)if(__gcd(i,t/i)==x){
            ans+=2;
            if(i*i==t)ans--;
        }
    printf("%lld",ans);
}