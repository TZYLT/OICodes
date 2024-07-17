#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1010];
long long ans=0;
long long cnt(long long x){
    int a=0;
    while(x){
        if(x&1)a++;
        x>>=1;
    }
    return a;
}
long long sum(long long x){
    long long mul=1;
    for(int i=0;i<k;i++){
        if(mul>n)return 0;
        if(x&(1<<i))mul*=a[i];
    }
    return n/mul;
}
long long sol1(void){
    for(int i=1;i<(1<<k);i++)
        ans=ans+(cnt(i)&1?1:-1)*sum(i);
    return ans;
}
long long sol2(void){
    for(int i=1;i<=n;i++){
        int f=0;
        for(int j=0;j<k;j++)
            if(i%a[j]==0){f=1;break;}
        if(f==0)ans++;
    }
    return ans;
}
int main(){
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%lld",a+i);
    sort(a,a+k);
    if(k<=20)printf("%lld",n-sol1());
    else printf("%lld",sol2());
}