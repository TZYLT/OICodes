#include<bits/stdc++.h>
using namespace std;
#define p 1732073999
long long dp[51][51][2];
long long a[51];
long long t,n;
long long qpow(long long a,long long k){
    long long res=1;
    while(k){
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res%p;
}
int main(){
    scanf("%lld%lld",&t,&n);
    while(t--){
        scanf("%lld",&n);
        memset(dp,0,sizeof dp);
        memset(a,0,sizeof a);
        for(int i=50;i>=1;i--)
            a[i]=n%3,n/=3;
        
        dp[0][0][1]=1;
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                for(int k=0;k<=2;k++){
                    if(k<=a[i+1])dp[i+1][j+(k==1)][k==a[i+1]]=(dp[i+1][j+(k==1)][k==a[i+1]]+dp[i][j][1])%p;
                    dp[i+1][j+(k==1)][0]=(dp[i+1][j+(k==1)][0]+dp[i][j][0])%p;
                }
        //for(int i=0;i<=50;i++)
        //    printf("[%d]:%d\n",i,dp[50][i][0]+dp[50][i][1]);
        int ans=0;
        for(int i=0;i<=50;i++)
            ans=(ans+(dp[50][i][0]+dp[50][i][1])%p*qpow(2,i)%p)%p;
        printf("%lld\n",ans);
    }
}