#include<bits/stdc++.h>
using namespace std;
int C[5050][5050];
int dp[2][5050][5050],sum[2][5050][5050];
int low[5050][5050];
int a[5050];
int n,p;
int ans;
int main(){
    scanf("%d%d",&n,&p);
    C[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            if(j!=0)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
            else C[i][j]=C[i-1][j];
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        int t=0;
        for(int j=2;j<=i-1;j++)
            t=(t+1ll*(j+1)*C[i-1][j]%p)%p;
        t=1ll*t*a[i]%p;
        ans=(ans+t)%p;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++){
            int t=lower_bound(a+1,a+1+n,a[i]-a[j])-a;
            if(a[t]>a[i]-a[j])t--;
            low[i][j]=min(j-1,t);
        }
    //a[i]>a[j]
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[1][i][j]=low[i][j];
            ans=(ans+p-1ll*dp[1][i][j]*3%p*a[i]%p)%p;
            (dp[1][i][j]+=dp[1][i][j-1])%=p;
        }
    }
    for(int i=4;i<=15;i++){
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dp[i&1][j][k]=0;
        for(int j=1;j<=n;j++)
            for(int k=1;k<j;k++){
                dp[i&1][j][k]=dp[(i&1)^1][k][low[j][k]];
                ans=(ans+p-1ll*dp[i&1][j][k]*a[j]%p*i%p)%p;
                (dp[i&1][j][k]+=dp[i&1][j][k-1])%=p;
            }
    }
    printf("%d",ans);
}