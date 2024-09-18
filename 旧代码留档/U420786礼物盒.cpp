#include<bits/stdc++.h>
using namespace std;
long long n,r,x[200200],y[200200];
long double ans;
long double dis(int i,int j){
    return sqrtl(((long double)x[i]-x[j])*((long double)x[i]-x[j])+(long double)(y[i]-y[j])*(y[i]-y[j]));
}
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",x+i,y+i);
    if(n>=2)
        for(int i=1;i<=n-1;i++)
            ans+=dis(i,i+1);
    ans+=dis(1,n);
    ans+=(long double)r*(long double)2.0*(long double)3.141592653589793238462;
    printf("%.9Lf\n",ans);
}
