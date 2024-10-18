#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[101][15],a[101],b[101],c[101],n,m;
int sol1(){
    
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)
        c[i]=(c[i-1]+b[i])%10;
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=-(1ll<<45);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<i;k++)
                dp[i][j]=max(dp[i][j],dp[k][j-1]*(((c[i]-c[k])%10+10)%10));
    return dp[n][m];
}
int sol2(){
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)
        c[i]=(c[i-1]+b[i])%10;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=(1ll<<45);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<i;k++)
                dp[i][j]=min(dp[i][j],dp[k][j-1]*(((c[i]-c[k])%10+10)%10));
    return dp[n][m];
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),a[i+n]=a[i];
    int ans1=-(1ll<<45),ans2=(1ll<<45);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=i+n-1;j++)
            b[j-i+1]=a[j];
        ans1=max(ans1,sol1());
        ans2=min(ans2,sol2());
    }
    printf("%lld\n%lld\n",ans2,ans1);
}