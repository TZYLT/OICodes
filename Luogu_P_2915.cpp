#include<bits/stdc++.h>
using namespace std;
long long dp[17][1<<16];
int n,t;
int a[101];
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int j=1;j<=n;j++)
        dp[j][1<<(j-1)]=1;
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(abs(a[j]-a[k])>t&&!((i>>(k-1))&1))
                    dp[k][i|(1<<(k-1))]+=dp[j][i];
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i][(1<<n)-1];
    cout<<ans<<endl;
}