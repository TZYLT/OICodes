#include<bits/stdc++.h>
using namespace std;
int dp[55][55];
string s;
int n;
int main(){
    cin>>s;
    n=s.size();
    s=" "+s;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for(int len=2;len<=n;len++)
        for(int l=1,r=len;r<=n;l++,r++){
            if(s[l]==s[r])dp[l][r]=min(dp[l+1][r],dp[l][r-1]);
            for(int i=l;i<r;i++)
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
        }
    printf("%d\n",dp[1][n]);

}