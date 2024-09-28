#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
inline bool check(int s1,int s2,int t){
    if((s1<<1)&t)return 0;
    if((s1>>1)&t)return 0;
    if((s2<<2)&t)return 0;
    if((s2>>2)&t)return 0;
    return 1;
}
int dp[101][41][1<<6][1<<6];
int n,m,h;
int main(){
    cin>>m>>n>>h;
    dp[0][0][0][0]=1;
    for(int i=0;i<n;i++)
        for(int d=0;d<=h;d++)
            for(int j=0;j<(1<<m);j++)
                for(int k=0;k<(1<<m);k++)
                    if(check(j,k,0))
                    for(int t=0;t<(1<<m);t++)
                        if(check(j,k,t))
                            dp[i+1][d+__builtin_popcount(t)][k][t]=(dp[i+1][d+__builtin_popcount(t)][k][t]+dp[i][d][j][k])%p;
    int ans=0;
    for(int k=0;k<(1<<m);k++)
        for(int t=0;t<(1<<m);t++)
            ans=(ans+dp[n][h][k][t])%p;
    cout<<ans<<endl;
}