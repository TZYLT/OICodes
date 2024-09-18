#include<bits/stdc++.h>
using namespace std;
#define M 10010
int w[M],id[M],dp[M];
vector<int> edge[10010];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        int y;
        scanf("%d",w+x);
        while(1){
            scanf("%d",&y);
            if(y==0)break;
            edge[y].push_back(x);
            id[x]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(id[i]==0)q.push(i),dp[i]=w[i];
    while(q.size()){
        int x=q.front();q.pop();
        for(auto c:edge[x])id[c]--;
        for(auto c:edge[x])dp[c]=max(dp[c],dp[x]+w[c]);
        for(auto c:edge[x])if(id[c]==0)q.push(c);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
}