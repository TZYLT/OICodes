#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100100],dp[100100];
int q[100100],ds[100100],h=0,t=1;
signed main(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i),a[i]+=a[i-1];
    for(int i=0;i<=n;i++){
        ds[i]=dp[i-1]-a[i];
        while(h-t+1>0&&q[t]<i-k)t++;
        while(h-t+1>0&&ds[q[h]]<ds[i])h--;
        q[++h]=i;
        dp[i]=ds[q[t]]+a[i];
    }
    printf("%lld\n",dp[n]);
}