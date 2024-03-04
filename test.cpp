#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
const long long mod=998244353;
int a[100000000];
int main(){
    for(int i=1;i<=1e8-10;i++)
        a[i]=i;
    long long ans=reduce(a+1,a+99999989,0,plus<long long>() );
    printf("%lld\n",ans);
}大吉大利，今晚吃鸡 ---QianXiquq 20240304