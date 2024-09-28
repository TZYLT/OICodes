#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[2][1<<10][1<<10];
int a[101];
inline bool check(int s1,int s2,int t,int i){
    if((s1&t)|(s2&t)|(a[i]&t))return 0;
    if(((t<<1)&t)|((t<<2)&t)|((t>>1)&t)|((t>>2)&t))return 0;
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
            a[i]=(a[i]<<1)|(s[j-1]=='H');
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<m);j++)
            for(int k=0;k<(1<<m);k++)
                dp[(i+1)&1][j][k]=0;
        for(int j=0;j<(1<<m);j++){
            if(check(0,0,j,0))
            for(int k=0;k<(1<<m);k++){
                if(check(0,j,k,0))
                for(int t=0;t<(1<<m);t++)
                    if(check(j,k,t,i+1))
                        dp[(i+1)&1][k][t]=max(dp[(i+1)&1][k][t],dp[i&1][j][k]+__builtin_popcount(t));
            }
        }
    }
    int ans=0;
    for(int j=0;j<(1<<m);j++)
        for(int k=0;k<(1<<m);k++)
            ans=max(ans,dp[n&1][j][k]);
    printf("%d\n",ans);
}