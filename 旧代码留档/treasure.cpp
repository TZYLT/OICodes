#include<bits/stdc++.h>
using namespace std; 

struct e{
    int la,v;
};
vector<e> in[1010];
int n,m,t,a[1010];
int dp[510][1010];
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),dp[0][i]=a[i];
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        in[y].push_back({x,z});
    }
    int ans=0;
    for(int c=1;c<=t;c++)
        for(int i=1;i<=n;i++)
            for(auto edge:in[i])
                if(c-edge.v>=0)dp[c][i]=max(dp[c][i],dp[c-edge.v][edge.la]+a[i]);
    
    for(int i=1;i<=t;i++)
        for(int c=1;c<=n;c++)
        ans=max(dp[i][c],ans);
    printf("%d\n",ans);
}