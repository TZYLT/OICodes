#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int dp[505][505][505];

int main(){
    freopen("bracket.in","r",stdin);
    freopen("bracket.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>s;
        int n=s.size();
        memset(dp,0xcf,sizeof dp);
        dp[0][0][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=1;k<=(n+1)/2;k++){
                    if(s[i-1]=='('){
                        if(j>=1)dp[i][j][k]=max(dp[i-1][j-1][k-1],dp[i][j][k]);
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                    }else{
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+1][k-1]+1);
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                    }
                }
        int ans=0;
        for(int i=0;i<=(n+1)/2;i++)
            ans=max(ans,dp[n][0][i]);
        printf("%d\n",ans);
    }   
}