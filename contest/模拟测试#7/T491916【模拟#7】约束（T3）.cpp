#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[1010],b[1010];
vector<int> id[1010];
long long f(long long i,long long j){
    if(i<0)return 0;
    if(j==0)return i;
    else return (f(i+b[j],j-1)-f((i+b[j])/a[j],j-1))-(f(b[j],j-1)-f((b[j])/a[j],j-1));
}
int main(){
    scanf("%lld%lld",&k,&n);
    for(int i=1;i<=k;i++)
        scanf("%d%d",a+i,b+i);
    printf("%lld\n",f(n,k));
}
