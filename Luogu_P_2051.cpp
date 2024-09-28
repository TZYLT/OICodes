#include<bits/stdc++.h>
using namespace std;
#define p 9999973
int dp[101][101][101];
int n,m;
void add(int &a,int b){a=(a+b)%p;}
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
    cin>>n>>m;
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=m;k++){
                add(dp[i+1][j][k],dp[i][j][k]);
                if(m-j-k>=1)add(dp[i+1][j+1][k],1ll*dp[i][j][k]*(m-j-k)%p);
                if(j>=1)add(dp[i+1][j-1][k+1],1ll*dp[i][j][k]*j%p);
                if(m-j-k>=2)add(dp[i+1][j+2][k],1ll*dp[i][j][k]*(m-j-k)%p*(m-j-k-1)*qpow(2,p-2)%p%p);
                if(j>=2)add(dp[i+1][j-2][k+2],1ll*dp[i][j][k]*j%p*(j-1)%p*qpow(2,p-2)%p);
                if(m-j-k>=1&&j>=1)add(dp[i+1][j][k+1],1ll*dp[i][j][k]*(m-j-k)%p*j%p);
            }
    int ans=0;
    for(int j=0;j<=m;j++)
        for(int k=0;k<=m;k++)
            ans=(ans+dp[n][j][k])%p;
    cout<<ans<<endl;
}