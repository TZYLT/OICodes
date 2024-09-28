#include<bits/stdc++.h>
using namespace std;
int n,nn,m;
vector<pair<int,int> > rg(400200);
vector<pair<int,int> > tp,id;
int r[400400];
int dp[31][400200];
int ans[200200];

int main(){
    scanf("%d%d",&n,&m);
    nn=n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&rg[i].first,&rg[i].second);
    for(int i=1;i<=n;i++)
        if(rg[i].first>rg[i].second)rg[i].second+=m;
    for(int i=1;i<=n;i++)
        //if(rg[i].second<=m)
            rg[++nn]=make_pair(rg[i].first+m,rg[i].second+m);
    for(int i=1;i<=nn;i++)
        tp.push_back({rg[i].first,0}),tp.push_back({rg[i].second,1});
    for(int i=1;i<=n;i++)
        id.push_back({rg[i].first,i});
    sort(tp.begin(),tp.end());
    sort(id.begin(),id.end());
    int cl=0,cr=0;
    for(auto c:tp)
        if(!c.second)cl++;
        else dp[0][++cr]=cl;  
    
    for(int j=1;j<=30;j++)    
        for(int i=1;i<=nn;i++)
            dp[j][i]=dp[j-1][dp[j-1][i]];
    for(int i=1;i<=n;i++){
        int k=i,ct=0;
        for(int j=30;j>=0;j--)
            if(dp[j][k]<n+i)
                k=dp[j][k],ct+=(1<<j);
        ans[id[i-1].second]=ct+1;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
}