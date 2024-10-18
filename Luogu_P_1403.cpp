#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        ans+=(n/i);
    printf("%lld\n",ans);
}