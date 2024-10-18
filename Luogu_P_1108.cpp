#include<bits/stdc++.h>
using namespace std;
int dp[5050],sum[5050],maxx;
int n,a[5050];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    sum[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)
            if(a[i]<a[j])
                dp[i]=max(dp[i],dp[j]+1);
        if(dp[i]==0)dp[i]++;
        maxx=max(maxx,dp[i]);
        for(int j=1;j<i;j++)
            if(dp[i]==dp[j]&&a[i]==a[j])
                sum[j]=0;
            else if(dp[i]==dp[j]+1&&a[i]<a[j])
                sum[i]+=sum[j];
        if(sum[i]==0)sum[i]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(dp[i]==maxx)
            ans+=sum[i];
    printf("%d %d",maxx,ans);
}