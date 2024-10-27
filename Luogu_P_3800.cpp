#include<bits/stdc++.h>
using namespace std;
int _map[4040][4040];
int dp[4040][4040];
int q[10010],h,t;
int n,m,k,T;
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&T);
    for(int i=1;i<=k;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        _map[x][y]=z;
    }
    for(int i=1;i<=n;i++){
        t=1,h=0;
        for(int j=1;j<=m;j++){
            while(h-t+1>0&&q[t]<j-T)t++;
            while(h-t+1>0&&dp[i-1][q[h]]<dp[i-1][j])h--;
            q[++h]=j;
            dp[i][j]=dp[i-1][q[t]]+_map[i][j];
        }
        t=1,h=0;
        for(int j=m;j>=1;j--){
            while(h-t+1>0&&q[t]>j+T)t++;
            while(h-t+1>0&&dp[i-1][q[h]]<dp[i-1][j])h--;
            q[++h]=j;
            dp[i][j]=max(dp[i][j],dp[i-1][q[t]]+_map[i][j]);
        }
    }
    int ans=0;
    for(int j=1;j<=m;j++)
        ans=max(ans,dp[n][j]);
    printf("%d\n",ans);
}