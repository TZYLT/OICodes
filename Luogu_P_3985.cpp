#include<bits/stdc++.h>
using namespace std;
pair<int,int> it[303];
long long dp[30300];
int n,w;
int maxn;
int main(){
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&it[i].second,&it[i].first),maxn=max(maxn,it[i].second);
    if(maxn<=300){
        w=min(w,maxn*n);
        for(int i=1;i<=n;i++)
            for(int j=w;j>=it[i].second;j--)
                dp[j]=max(dp[j],dp[j-it[i].second]+it[i].first);
        long long ans=0;
        for(int i=1;i<=w;i++)
            ans=max(ans,dp[i]);
        printf("%lld\n",ans);
    }else{
        sort(it+1,it+1+n);
        long long ans=0;
        for(int i=1;i<=(w/maxn);i++)
            ans+=it[n-i+1].first;
        printf("%lld\n",ans);
    }
}