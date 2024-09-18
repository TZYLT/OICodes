#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long n,t;
const long double c=0.39207289814597337133672322074163;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",(long long)(c*n));
    }
}