#include<bits/stdc++.h>
using namespace std;
int dp[15][1<<13];
int a[15];
bool check(int s,int t,int i){
    return ((s&t)==0)&&((t&(~a[i]))==0)&&((t&(t>>1))==0)&&((t&(t<<1))==0);
}
int n,m,t;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>t;
            a[i]=(a[i]<<1)|t;
        }
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<m);j++)
            for(int k=0;k<(1<<m);k++)
                if(check(j,k,i+1))
                    dp[i+1][k]=(dp[i+1][k]+dp[i][j])%100000000;
    int ans=0;
    for(int i=0;i<(1<<m);i++)
        ans=(ans+dp[n][i])%100000000;
    cout<<ans<<endl;
}