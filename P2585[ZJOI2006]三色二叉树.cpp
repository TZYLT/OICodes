#include<bits/stdc++.h>
using namespace std;
int dp[500100][3];
string s;
int head;
void dfs1(int l){
    head=max(l,head);
    int lc=0,rc=0;
    if(s[l]=='2')lc=l+1,dfs1(l+1),rc=head+1,dfs1(head+1);
    else if(s[l]=='1')lc=l+1,dfs1(l+1);
    if(s[l]=='2')dp[l][0]=max({dp[lc][1]+dp[rc][2]+1,dp[lc][2]+dp[rc][1]+1});
    else if(s[l]=='1')dp[l][0]=max(dp[lc][1],dp[lc][2])+1;
    else dp[l][0]=1;
    if(s[l]=='2')dp[l][1]=max({dp[lc][0]+dp[rc][2],dp[lc][2]+dp[rc][0]});
    else if(s[l]=='1')dp[l][1]=max(dp[lc][0],dp[lc][2]);
    else dp[l][1]=0;
    if(s[l]=='2')dp[l][2]=max({dp[lc][0]+dp[rc][1],dp[lc][1]+dp[rc][0]});
    else if(s[l]=='1')dp[l][2]=max(dp[lc][0],dp[lc][1]);
    else dp[l][2]=0;
}
void dfs2(int l){
    head=max(l,head);
    int lc=0,rc=0;
    if(s[l]=='2')lc=l+1,dfs2(l+1),rc=head+1,dfs2(head+1);
    else if(s[l]=='1')lc=l+1,dfs2(l+1);
    if(s[l]=='2')dp[l][0]=min({dp[lc][1]+dp[rc][2]+1,dp[lc][2]+dp[rc][1]+1});
    else if(s[l]=='1')dp[l][0]=min(dp[lc][1],dp[lc][2])+1;
    else dp[l][0]=1;
    if(s[l]=='2')dp[l][1]=min({dp[lc][0]+dp[rc][2],dp[lc][2]+dp[rc][0]});
    else if(s[l]=='1')dp[l][1]=min(dp[lc][0],dp[lc][2]);
    else dp[l][1]=0;
    if(s[l]=='2')dp[l][2]=min({dp[lc][0]+dp[rc][1],dp[lc][1]+dp[rc][0]});
    else if(s[l]=='1')dp[l][2]=min(dp[lc][0],dp[lc][1]);
    else dp[l][2]=0;
}
int main(){
    cin>>s;
    dfs1(0);
    cout<<max({dp[0][1],dp[0][2],dp[0][0]})<<' ';

    head=0;
    memset(dp,0x3f,sizeof dp);
    dfs2(0);
    cout<<min({dp[0][1],dp[0][2],dp[0][0]})<<endl;
}