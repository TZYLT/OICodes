#include<bits/stdc++.h>
using namespace std;
int dp[1<<23];
int p[30];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    if(m==n*(n-1)/2){
        printf("0");
        return 0;
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<n;i++)
        p[i]=(1<<i),dp[1<<i]=0;
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        p[x]|=(1<<y);
        p[y]|=(1<<x);
    }
    for(int i=1;i<=n;i++)
        dp[p[i]]=1;
    for(int i=0;i<(1<<n);i++){
        if(dp[i]>(1<<30))continue;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                dp[i|p[j]]=min(dp[i|p[j]],dp[i]+1);
    }
    printf("%d\n",dp[(1<<n)-1]);
}