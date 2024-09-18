#include<bits/stdc++.h>
using namespace std;
int dp[2][5050],sum[2][5050];
int n,m;
string s,t;
int main(){
    cin>>s>>t;
    s=" "+s;
    t=" "+t;
    n=s.size()-2;
    m=t.size()-2;
    for(int i=0;i<=m;i++)
        sum[0][i]=1; 
    for(int i=1;i<=n;i++){
        sum[i&1][0]=1;
        for(int j=1;j<=m;j++){
            sum[i&1][j]=0;
            dp[i&1][j]=max(dp[i&1][j-1],dp[(i-1)&1][j]);
            if(s[i]==t[j])dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-1]+1);

            if(dp[i&1][j]==dp[i&1][j-1])sum[i&1][j]=(sum[i&1][j]+sum[i&1][j-1])%100000000;
            if(dp[i&1][j]==dp[(i-1)&1][j])sum[i&1][j]=(sum[i&1][j]+sum[(i-1)&1][j])%100000000;
            if(dp[i&1][j]==(dp[(i-1)&1][j-1]+1)&&s[i]==t[j])sum[i&1][j]=(sum[i&1][j]+sum[(i-1)&1][j-1])%100000000;
            if(dp[i&1][j]==dp[(i-1)&1][j-1]&&s[i]!=t[j])sum[i&1][j]=(sum[i&1][j]-sum[(i-1)&1][j-1])%100000000;
        }
    }
    printf("%d\n%d\n",dp[n&1][m],(sum[n&1][m]+100000000)%100000000);
}