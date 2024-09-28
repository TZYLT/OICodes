#include<bits/stdc++.h>
using namespace std;
int dp[100100],used[100100];
int a[101],c[101];
int n,m;
int main(){
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0)return 0;
        memset(dp,0,sizeof dp);
        memset(used,0,sizeof used);
        memset(a,0,sizeof a);
        memset(c,0,sizeof c);

        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=n;i++)
            scanf("%d",c+i);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                used[j]=0;
            for(int j=a[i];j<=m;j++)
                if(!dp[j]&&dp[j-a[i]]&&used[j-a[i]]<c[i])
                    dp[j]=1,used[j]=used[j-a[i]]+1;
        }
        int ans=0;
        for(int i=1;i<=m;i++)
            ans+=dp[i];
        printf("%d\n",ans);
    }
}