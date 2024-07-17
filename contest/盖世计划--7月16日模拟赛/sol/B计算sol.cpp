#include<bits/stdc++.h>
using namespace std;
long long s[200200][101];
bool v[200200][101];
long long n,k,a[1010];
long long f(long long i,long long j){
    if(i==0)return 0;
    if(j==0)return i;
    if(i<=200000){
        if(v[i][j])return s[i][j];
        else {
            v[i][j]=1;
            return s[i][j]=f(i,j-1)-f(i/a[j],j-1);
        }
    }else return f(i,j-1)-f(i/a[j],j-1);
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%lld",a+i);
    printf("%lld\n",f(n,k));
}