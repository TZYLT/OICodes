#include<bits/stdc++.h>
using namespace std;
int T,mp,w;
long long dp[2020][2020];
long long tp[2020];
int q[10100],h,t;
int main(){
    scanf("%d%d%d",&T,&mp,&w);
    memset(dp,0xcf,sizeof dp);
    for(int i=1;i<=T;i++){
        int ap,bp,as,bs;
        scanf("%d%d%d%d",&ap,&bp,&as,&bs);
        for(int j=0;j<=as;j++)
            dp[i][j]=max(dp[i][j],-1ll*ap*j);
        for(int j=0;j<=mp;j++)
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if(i-w-1>=0){
            for(int j=0;j<=mp;j++)
                tp[j]=dp[i-w-1][j]+1ll*j*ap;
            h=0;t=1;
            for(int j=0;j<=mp;j++){
                while(h-t+1>0&&q[t]<j-as)t++;
                while(h-t+1>0&&tp[q[h]]<tp[j])h--;
                q[++h]=j;
                dp[i][j]=max(dp[i][j],tp[q[t]]-1ll*j*ap);
            }
            for(int j=0;j<=mp;j++)
                tp[j]=dp[i-w-1][j]+1ll*j*bp;
            h=0;t=1;
            for(int j=mp;j>=0;j--){
                while(h-t+1>0&&q[t]>j+bs)t++;
                while(h-t+1>0&&tp[q[h]]<tp[j])h--;
                q[++h]=j;
                dp[i][j]=max(dp[i][j],tp[q[t]]-1ll*j*bp);
            }
        }
    }
    long long ans=0;
    for(int j=0;j<=mp;j++)  
        ans=max(ans,dp[T][j]);
    printf("%lld\n",ans);
}