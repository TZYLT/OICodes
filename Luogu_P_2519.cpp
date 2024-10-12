#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<int,int>,int> st;
int dp[100100],sum[100100];
vector<pair<int,int> > opt[100100];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x++;y=n-y;
        if(x>y)continue;
        st[{x,y}]++;
    }
    for(auto c:st)
        opt[c.first.second].push_back({c.first.first,min(c.second,c.first.second-c.first.first+1)});
    for(int i=1;i<=n;i++){
        for(auto c:opt[i])
            dp[i]=max(dp[i],sum[c.first-1]+c.second);
        sum[i]=max(sum[i-1],dp[i]);
    }
    printf("%d\n",n-sum[n]);
}