#include<bits/stdc++.h>
using namespace std;
int a[100100],b[50],dp[100100],n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=31;j++)
            if((a[i]>>(j-1))&1)
                dp[i]=max(dp[i],b[j]+1);
        for(int j=1;j<=31;j++)
            if((a[i]>>(j-1))&1)
                b[j]=max(b[j],dp[i]);
        ans=max(dp[i],ans);
    }

    printf("%d\n",ans);
}