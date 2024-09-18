#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        printf((n&1)?"Yes\n":"No\n");
    }
}