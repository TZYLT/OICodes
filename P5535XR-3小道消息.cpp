#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool isp(long long x){
    if(x==1)return 0;
    for(long long i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int main(){
    scanf("%lld%lld",&n,&k);
    if(isp(k+1)&&k*2>=n)
        printf("1\n");
    else printf("2\n");
}