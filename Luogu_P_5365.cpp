#include<bits/stdc++.h>
using namespace std;
long long dp[2000020];
long long n,m;
int k[1010],c[1010];
long long sum;
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",k+i);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i),sum+=1ll*k[i]*c[i]; 
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=c[i];j--)
            for(int t=0;t<=k[i]&&t*c[i]<=j;t++)
                dp[j]=max(dp[j],1ll*max(1,t)*dp[j-t*c[i]]);  
    }
    for(int i=0;i<=sum;i++)
        if(dp[i]>=m){
            printf("%d\n",i);
            return 0;
        }
}