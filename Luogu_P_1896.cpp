#include<bits/stdc++.h>
using namespace std;
long long dp[11][101][1<<11];
int n,k;
bool check(int s,int t){
    if(((t<<1)|(t>>1)|t)&s)return 0;
    if(((t<<1)|(t>>1))&t)return 0;
    return 1;
}
int main(){
    cin>>n>>k;
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int s=0;s<=k;s++)
            for(int j=0;j<(1<<n);j++)
                for(int t=0;t<(1<<n);t++)
                    if(check(j,t))
                        dp[i+1][s+__builtin_popcount(t)][t]+=dp[i][s][j];
    long long ans=0;
    for(int j=0;j<(1<<n);j++)
        ans+=dp[n][k][j];
    cout<<ans<<endl;
}