#include<bits/stdc++.h>
using namespace std;
int n,nn,m;
vector<pair<int,int> > rg(2000200);
vector<pair<int,int> > tp;
int dp[31][2000200];
int main(){
    scanf("%d%d",&m,&n);
    nn=n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&rg[i].first,&rg[i].second);
    for(int i=1;i<=n;i++)
        rg[i].first--;
    for(int i=1;i<=n;i++)
        if(rg[i].first>rg[i].second)rg[i].second+=m;
    for(int i=1;i<=n;i++)
        //if(rg[i].second<=m)
            rg[++nn]=make_pair(rg[i].first+m,rg[i].second+m);
    for(int i=1;i<=nn;i++)
        tp.push_back({rg[i].first,0}),tp.push_back({rg[i].second,1});
    sort(tp.begin(),tp.end());
    int cl=0,cr=0;
    for(auto c:tp)
        if(!c.second)cl++;
        else dp[0][++cr]=cl;  
    
    for(int j=1;j<=30;j++)    
        for(int i=1;i<=nn;i++)
            dp[j][i]=dp[j-1][dp[j-1][i]];
    int ans=0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        int k=i,ct=0;
        for(int j=29;j>=0;j--)
            if(dp[j][k]<n+i)
                k=dp[j][k],ct+=(1<<j);
        ans=min(ans,ct+1);
    }
    if(ans>n)printf("impossible\n");
    else printf("%d\n",ans);
            
}